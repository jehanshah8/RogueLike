#include "Action.hpp"

Action::Action() : message(""),
                   intValue(-1),
                   charValue(0),
                   owner(nullptr)
{
}

void Action::setMessage(const std::string &message)
{
    this->message = message;
}

void Action::setInValue(int value)
{
    intValue = value;
}

void Action::setCharValue(char value)
{
    charValue = value;
}

void Action::setOwner(const std::shared_ptr<Displayable> owner)
{
    this->owner = owner;
}