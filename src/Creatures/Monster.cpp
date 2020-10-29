#include "Monster.hpp"

void Monster::setType(char type) 
{
    this->type = type; 
}

const std::string Monster::toString() const
{
    std::string str = Creature::toString();

    str += "   type: " + std::to_string(type) + "\n";

    //std::cout << str << std::endl;
    return str;
}