#include "Monster.hpp"

Monster::Monster(const std::string &name, int room, int serial) : Creature(name, 'M', room, serial)
{
    //std::cout << "creating monster" << std::endl;
}

void Monster::setType(char type)
{
    //this->type = type;
    displayCode = type; 
}

const std::string Monster::toString() const
{
    std::string str = Creature::toString();

    str += "\t\t\ttype: ";
    str += displayCode;
    str += "\n";

    //std::cout << str << std::endl;
    return str;
}