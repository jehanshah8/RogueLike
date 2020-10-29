#include "Monster.hpp"

Monster::Monster(const std::string &name, int room, int serial) : Creature(name, room, serial),
                                                                  type('?')
{
    //std::cout << "creating monster" << std::endl; 
}

void Monster::setType(char type)
{
    this->type = type;
}

const std::string Monster::toString() const
{
    std::string str = Creature::toString();

    str += "\t\t\ttype: "; 
    str +=  type; 
    str += "\n"; 

    //std::cout << str << std::endl;
    return str;
}