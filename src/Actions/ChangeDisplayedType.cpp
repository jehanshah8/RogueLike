#include "ChangeDisplayedType.hpp"

ChangeDisplayedType::ChangeDisplayedType() : Action()
{
}

void ChangeDisplayedType::execute()
{
    owner->setDisplaycode(charValue);
    owner->leaveGrid();
    owner->Displayable::initializeDisplay();
}
