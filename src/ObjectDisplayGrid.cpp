#include "ObjectDisplayGrid.hpp"

ObjectDisplayGrid::ObjectDisplayGrid(const int gameHeight, const int gameWidth, const int topHeight, const int bottomHeight) : gameHeight(gameHeight),
																															   gameWidth(gameWidth),
																															   topHeight(topHeight),
																															   bottomHeight(bottomHeight),
																															   grid(gameWidth, std::vector<std::stack<char>>('D'))
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

void ObjectDisplayGrid::addObjectToDisplay(const int x, const int y, const char gridChar)
{
	if ((0 <= x) && (x < gameWidth))
	{
		// y between 0 and height
		if ((0 <= y) && (y < gameHeight))
		{
			// add new character to the internal character list
			grid[x][y].push(gridChar);
			// draws the character on the screen, note it is relative to 0,0 of the terminal
			mvaddch(y, x, gridChar);
		}
	}
}
//
//char ObjectDisplayGrid::getDisplayable(const int row, const int col) const
//{
//	return grid[row][col].top();
//}
//
//void ObjectDisplayGrid::removeObjectFromDisplay(const int row, const int col)
//{
//	grid[row][col].pop();
//}
//
//void ObjectDisplayGrid::setTopMessage(const int hitPoints, const int score)
//{
//	std::string topMessage = std::to_string(hitPoints) + "\n" + std::to_string(score) + "\n";
//	mvaddstr(0, topHeight, topMessage.c_str());
//	clrtoeol();
//}
//
//void ObjectDisplayGrid::setBottomMessage(const std::string &inventory, const std::string &message)
//{
//	std::string bottomMessage = message + "\n" + inventory + "\n";
//	mvaddstr(topHeight + gameHeight + bottomHeight, 0, bottomMessage.c_str());
//	clrtoeol();
//}
//
void ObjectDisplayGrid::update()
{
	// refreshes ncurses
	refresh();
}

ObjectDisplayGrid::~ObjectDisplayGrid()
{
	// free ncurses data
	endwin();
}