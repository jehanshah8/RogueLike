#include "ObjectDisplayGrid.hpp"

ObjectDisplayGrid::ObjectDisplayGrid(const int gameHeight, const int gameWidth, const int topHeight, const int bottomHeight) : gameHeight(gameHeight),
																															   gameWidth(gameWidth),
																															   topHeight(topHeight),
																															   bottomHeight(bottomHeight),
																															   //charGrid(gameWidth, std::vector<std::stack<char>>(gameHeight + topHeight + bottomHeight, std::stack<char>())),
																															   objectGrid(gameWidth, std::vector<std::stack<std::shared_ptr<Displayable>>>(gameHeight + topHeight + bottomHeight, std::stack<std::shared_ptr<Displayable>>())),
																															   keepRunning(true)
{
	// initializes ncurses
	initscr();
	// makes characters typed immediately available, instead of waiting for enter to be pressed
	cbreak();
	// stops typed characters from being shown, makes it easier to get keypresses
	noecho();
	// clears the screen to start
	clear();
}

void ObjectDisplayGrid::addObjectToDisplay(int x, int y, const std::shared_ptr<Displayable> displayable)
{
	if ((0 <= x) && (x < gameWidth))
	{
		if ((0 <= y) && (y < gameHeight))
		{
			objectGrid[x][y].push(displayable);
			mvaddch(y, x, displayable->getDisplayCode());
		}
	}
}

void ObjectDisplayGrid::removeObjectFromDisplay(int x, int y)
{
	if ((0 <= x) && (x < gameWidth))
	{
		if ((0 <= y) && (y < gameHeight))
		{
			if (!objectGrid[x][y].empty())
			{
				objectGrid[x][y].top().reset();
				objectGrid[x][y].pop();
				mvaddch(y, x, objectGrid[x][y].top()->getDisplayCode());
			}
		}
	}
}

void ObjectDisplayGrid::update()
{
	// refreshes ncurses
	refresh();
}

const std::shared_ptr<Displayable> ObjectDisplayGrid::getDisplayable(int x, int y) const
{
	if (objectGrid[x][y].empty())
    {
		return nullptr;
	}
	return objectGrid[x][y].top();
}

void ObjectDisplayGrid::setTopMessage(int hitPoints, int score)
{
	std::string topMessage;
	topMessage += "HP: " + std::to_string(hitPoints);
	topMessage += "\tScore: " + std::to_string(score) + "\n";
	mvaddstr(0, 0, topMessage.c_str());
	clrtoeol();
}

void ObjectDisplayGrid::setBottomMessagePack(const std::string &inventory)
{
	std::string bottomMessage = "pack: " + inventory;
	mvaddstr(topHeight + gameHeight, 0, bottomMessage.c_str());
	clrtoeol();
}

void ObjectDisplayGrid::setBottomMessageInfo(const std::string &message)
{
	std::string bottomMessage = "info: " + message;
	mvaddstr(topHeight + gameHeight + bottomHeight / 2, 0, bottomMessage.c_str());
	clrtoeol();
}

void ObjectDisplayGrid::removeAllObjects()
{
	for (auto &it1 : objectGrid)
	{
		for (auto &it2 : it1)
		{
			while (!it2.empty())
			{
				it2.top().reset();
				it2.pop();
			}
		}
		it1.clear();
	}
	objectGrid.clear();
	objectGrid.shrink_to_fit();
}

ObjectDisplayGrid::~ObjectDisplayGrid()
{
	// free ncurses data
	endwin();
}