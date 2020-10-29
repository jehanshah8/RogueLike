#include "ObjectDisplayGrid.hpp"

ObjectDisplayGrid::ObjectDisplayGrid(const int gameHeight, const int gameWidth, const int topHeight, const int bottomHeight) : gameHeight(gameHeight),
                                                                                                                               gameWidth(gameWidth),
                                                                                                                               topHeight(topHeight),
                                                                                                                               bottomHeight(bottomHeight)
{
    grid.reserve(gameHeight);
    for (auto &it : grid)
    {
        it.reserve(gameWidth);
    }

    // initializes ncurses
    initscr();
    // makes characters typed immediately available, instead of waiting for enter to be pressed
    cbreak();
    // stops typed characters from being shown, makes it easier to get keypresses
    noecho();
    // clears the screen to start
    clear();
}

void ObjectDisplayGrid::addObjectToDisplay(const int row, const int col, const char displayObject)
{
    grid[row][col].push(displayObject);
}

char ObjectDisplayGrid::getDisplayable(const int row, const int col) const
{
    return grid[row][col].top();
}

void ObjectDisplayGrid::removeObjectFromDisplay(const int row, const int col)
{
    grid[row][col].pop();
}

void ObjectDisplayGrid::setTopMessage(const int hitPoints, const int score)
{
    std::string topMessage = std::to_string(hitPoints) + "\n" + std::to_string(score) + "\n";
    mvaddstr(0, topHeight, topMessage.c_str());
    clrtoeol();
}

void ObjectDisplayGrid::setBottomMessage(const std::string &inventory, const std::string &message)
{
    std::string bottomMessage = message + "\n" + inventory + "\n";
    mvaddstr(topHeight + gameHeight + bottomHeight, 0, bottomMessage.c_str());
    clrtoeol();
}

void ObjectDisplayGrid::update(const char input) {
    switch (input)
		{
		// Dungeon
		case '?':
			// Help: ‘?’: show the different commands in the info section of the display
			dungeon->getHelp();
			break;
		case 'H':
			// Help ‘H’ <command>give more detailed information about the specified
			//command in the info section ofthe display.
			dungeon->getHelp(std::tolower(getchar()));
			break;
		case 'E':
			bool confirm = std::tolower(getchar()) == 'y';
			if (confirm)
			{
				dungeon->endGame();
			}
			break;

		// Player
		case 'h':
			player->moveLeft();
			break;
		case 'l':
			player->moveRight();
			break;
		case 'k':
			player->moveUp();
			break;
		case 'j':
			player->moveDown();
			break;
		case 'i':
			// show pack contents
			player->getInventory();
			break;
		case 'c':
			// Change, or take off armor ‘c’: armor that is being worn is taken off
			// and placed in the pack. If not armor is being worn
			// a message should be shown in the info area of the game display.
			player->setArmor();
			break;
		case 'd':
			// Drop ‘d’ <integer>: drop item <integer> from the pack.
			// If the <integer> does not refer to an item in the pack and
			// informational message is printed on the game display in the info area.
			player->dropItem(getchar());
			break;
		case 'r':
			// Read an item ‘r’ <integer>: the item specified by the integer
			// must be a scroll that is in the pack. It causes the scroll to perform its actions.
			player->readScroll(getchar());
			break;
		case 'p':
			// Pick up an item from the dungeon floor ‘p’: pick up the visible item
			// on the dungeon floor location thatthe player is standing on.
			// If multiple items are in the location, only the top item is picked up.
			player->pickUp();
			break;
		case 'T':
			// Take out a weapon ‘T’ <integer>: take the sword identified by <integer> from the pack.
			// If the identified item is not a sword, or no such item exists,
			// show a message in the info area of the game display.
			player->weildSword(getchar());
			break;
		case 'w':
			// Wear item ‘w’ <integer>: take the armor identified by <integer> from the pack
			// and make it the armor being worn. If the identified item is not armor,
			// or no such item exists, show a message in the info area of the game display.
			player->wearArmor(getchar());
			break;

		default:
			// C is not happy about appending a character to a string apparently
			std::string message = "Unknown key '";
			message += input;
			grid->writeLine(2, message + "'");
			break;
		}
	// refreshes ncurses
	refresh();
}

ObjectDisplayGrid::~ObjectDisplayGrid()
{
    // free ncurses data
    endwin();
}