#include "GridObject.hpp"

GridObject::GridObject(char displayCode) : displayCode(displayCode) {}

const char GridObject::getDisplayCode() const
{
	return displayCode;
}

void GridObject::setDisplayCode(char displayCode)
{
	this->displayCode = displayCode;
}
