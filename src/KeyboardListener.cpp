#include "KeyboardListener.hpp"

#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(const std::shared_ptr<ObjectDisplayGrid> grid, const std::shared_ptr<Dungeon> dungeon) : grid(grid),
																															dungeon(dungeon),
																															player(dungeon->getPlayer())
{
}

void KeyboardListener::run()
{
	grid->writeLine(0, "Press 'x' to exit");
	isRunning = true;
	char input;
	do
	{
		input = getchar();
		grid->update(const char input);
	} while (isRunning && input != EOF);
}