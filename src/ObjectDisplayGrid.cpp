#include "ObjectDisplayGrid.hpp"

ObjectDisplayGrid::ObjectDisplayGrid(const int gameHeight, const int gameWidth, const int topHeight, const int bottomHeight) : gameHeight(gameHeight),
																															   gameWidth(gameWidth),
																															   topHeight(topHeight),
																															   bottomHeight(bottomHeight),
																															   grid(gameWidth, std::vector<std::stack<char>>(gameHeight + topHeight + bottomHeight, std::stack<char>()))
{
	std::cout << grid.size() << std::endl;
	std::cout << grid[0].size() << std::endl;
	//for(auto &it : grid)
	//{
	//	for(auto &it2 : it)
	//	{
	//		it2.push('D');
	//	}
	//}
	// initializes ncurses
	initscr();
	// makes characters typed immediately available, instead of waiting for enter to be pressed
	cbreak();
	// stops typed characters from being shown, makes it easier to get keypresses
	noecho();
	// clears the screen to start
	clear();
}

void ObjectDisplayGrid::addObjectToDisplay(const int x, const int y, const char gridChar)
{
	if ((0 <= x) && (x < gameWidth))
	{
		if ((0 <= y) && (y < gameHeight))
		{
			grid[x][y].push(gridChar);
			mvaddch(y, x, gridChar);
		}
	}
}

void ObjectDisplayGrid::removeObjectFromDisplay(const int x, const int y)
{
	if ((0 <= x) && (x < gameWidth))
	{
		if ((0 <= y) && (y < gameHeight))
		{
			grid[x][y].pop();
		}
	}
}

void ObjectDisplayGrid::update()
{
	// refreshes ncurses
	refresh();
}

//char ObjectDisplayGrid::getDisplayable(const int row, const int col) const
//{
//	return grid[row][col].top();
//}
//

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
	std::string bottomMessage = "pack: "; //+ inventory + "\n";
	mvaddstr(topHeight + gameHeight, 0, bottomMessage.c_str());
	//topHeight + gameHeight + bottomHeight
	clrtoeol();
}

void ObjectDisplayGrid::setBottomMessageInfo(const std::string &message)
{
	std::string bottomMessage = "info: "; // + message + "\n";
	mvaddstr(topHeight + gameHeight + bottomHeight / 2, 0, bottomMessage.c_str());
	//topHeight + gameHeight + bottomHeight
	clrtoeol();
}

ObjectDisplayGrid::~ObjectDisplayGrid()
{
	// free ncurses data
	endwin();
}