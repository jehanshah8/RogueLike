#include "Sword.hpp"
#include "../Actions/Action.hpp"

Sword::Sword(const std::string &name, int room, int serial) : Item(name, ')',room, serial)
{
    //std::cout << "creating sword" << std::endl;
}

void Sword::equip()
{
    isEquipped = 'w';
}