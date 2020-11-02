#include "Item.hpp"

Item::Item(const std::string &name, char displayCode, int room, int serial) : Displayable(name, displayCode),
                                                                              room(room),
                                                                              serial(serial),
                                                                              itemIntValue(0)
{
}

void Item::setItemIntValue(const int value)
{
    itemIntValue = value;
}

void Item::setOwner(const std::shared_ptr<Player> owner)
{
    this->owner = owner;
}

const std::string Item::toString(int indentation) const
{
    std::string str = Displayable::toString(indentation);
    if (indentation == 4)
    {
        str += "\t";
    }
    str += "\t\t\titemIntValue: " + std::to_string(itemIntValue) + "\n";
    if (indentation == 4)
    {
        str += "\t";
    }
    str += "\t\t\troom: " + std::to_string(room) + "\n";
    if (indentation == 4)
    {
        str += "\t";
    }
    str += "\t\t\tserial: " + std::to_string(serial) + "\n";
    //std::cout << str << std::endl;
    return str;
}