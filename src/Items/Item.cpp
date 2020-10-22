#include "Item.hpp"

Item::Item(const std::string &name, const int room, const int serial) : Displayable(name),
                                                                        room(room),
                                                                        serial(serial)
{
    setId(room, serial); 
}

void Item::setItemIntValue(const int value) {
    itemIntValue = value; 
}

void Item::setOwner(const std::shared_ptr<Creature> owner) {
    this->owner = owner;  
}