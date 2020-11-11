#include "GridChar.hpp"

GridChar::GridChar(char displayCode) : displayCode(displayCode) {}

const char GridChar::getDisplayCode() const
{
	return displayCode;
}

void GridChar::setDisplayCode(char displayCode)
{
	this->displayCode = displayCode;
}
