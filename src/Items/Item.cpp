#include "Item.hpp"
#include "../Actions/Action.hpp"

Item::Item(const std::string &name, char displayCode, int room, int serial) : Displayable(name, displayCode),
                                                                              itemIntValue(0),
                                                                              isEquipped(0),
                                                                              room(room),
                                                                              serial(serial)

{
}

void Item::setName(const std::string& name)
{
    this->name = name;
}

void Item::setItemIntValue(const int value)
{
    itemIntValue = value;
}

const int Item::getIntValue() const
{
    return itemIntValue;
}

void Item::equip()
{
    isEquipped = '*';
}

void Item::unequip()
{
    isEquipped = 0;
}

const bool Item::getIsEquipped() const
{
    return isEquipped != 0;
}

const std::string Item::getIsEquippedStr() const
{
    std::string str = "";
    if (isEquipped != 0)
    {
        str += " (";
        str += isEquipped;
        str += ")";
    }
    return str;
}

void Item::setOwner(const std::shared_ptr<Player> owner)
{
    this->owner = owner;
}

const std::shared_ptr<Player> Item::getOwner() const
{
    return owner;
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

void Item::addAction(const std::shared_ptr<Action> action)
{
    actions.push_back(action);
    action->setOwner(Displayable::downcasted_shared_from_this<Item>());
}

void Item::releaseAllActions()
{
    for (auto &it : actions)
    {
        it->setOwner(nullptr);
    }
}