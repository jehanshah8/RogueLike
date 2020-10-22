#include "KeyboardListener.hpp"

#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(std::shared_ptr<ObjectDisplayGrid> grid) : grid(grid) {}

void KeyboardListener::run() {
	grid->writeLine(0, "Press 'x' to exit");
	isRunning = true;
	char input;
	do {
		// wait for next input
		// lowercase so 'x' and 'X' are treated as the same
		input = std::tolower(getchar());

		switch (input) {
		// press X to stop
		case 'x':
			isRunning = false;
			grid->writeLine(2, "Exiting...");
			break;
		case 'e':
			grid->writeLine(2, "You found the easter egg, congrats");
			break;
		default:
			// C is not happy about appending a character to a string apparently
			std::string message = "Unknown key '";
			message += input;
			grid->writeLine(2, message + "'");
			break;
		}
		grid->update();
	} while (isRunning && input != EOF);
}