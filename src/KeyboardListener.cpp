#include "KeyboardListener.hpp"
//#include "Dungeon.hpp"

KeyboardListener::KeyboardListener() : //Subject(),
									   keepRunning(true)
{
}

void KeyboardListener::registerObserver(std::shared_ptr<Observer> observer)
{
	observers.push_back(observer);
	//observers.insert(observer);
}

void KeyboardListener::removeObserver(std::shared_ptr<Observer> observer)
{
	//	//std::unordered_set<std::shared_ptr<Observer>>::const_iterator it = observers.find(observer);
	//	observer.reset();
	//observers.erase(observer);
}

void KeyboardListener::notifyObservers()
{
	while (keepRunning)
	{
		if (!commandHistory.empty())
		{
			for (auto &it : observers)
			{
				it->update(commandHistory.front());
			}
			commandHistory.pop();
		}
	}
}

void KeyboardListener::getInput()
{
	while (keepRunning)
	{
		commandHistory.push(getchar());
	}
}

void KeyboardListener::run()
{
	std::thread inputListener(&KeyboardListener::getInput, this);
	std::thread notifier(&KeyboardListener::notifyObservers, this);
	inputListener.join();
	notifier.join();

	for (auto &it : observers)
	{
		it.reset();
	}
}

void KeyboardListener::kill()
{
	keepRunning = false;
}

/**
do
	{
		input = getchar();
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
		//grid->update(const char input);
	} while (isRunning && input != EOF);
	*/
