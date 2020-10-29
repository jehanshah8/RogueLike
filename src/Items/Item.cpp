#include "Item.hpp"

Item::Item(const std::string &name, int room, int serial) : Displayable(name),
                                                            room(room),
                                                            serial(serial), 
                                                            itemIntValue(0)
{
}

void Item::setItemIntValue(const int value)
{
    itemIntValue = value;
}

void Item::setOwner(const std::shared_ptr<Creature> owner)
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
    
    //std::cout << str << std::endl;
    return str;
}