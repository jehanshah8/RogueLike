#include "Armor.hpp"

Armor::Armor(const std::string &name, int room, int serial) : Item(name, ']', room, serial)
{
    //std::cout << "creating armor" << std::endl;
}