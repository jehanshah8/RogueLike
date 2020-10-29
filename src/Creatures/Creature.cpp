#include "Creature.hpp"

Creature::Creature(const std::string &name, int room, int serial) : Displayable(name),
                                                                    room(room),
                                                                    serial(serial)
{
}

void Creature::setHp(int hp)
{
    this->hp = hp;
}

void Creature::setMaxHit(int maxHit)
{
    this->maxHit = maxHit;
}

void Creature::addDeathAction(const std::shared_ptr<CreatureAction> deathAction)
{
    deathActions.push_back(deathAction);
}

void Creature::addHitAction(const std::shared_ptr<CreatureAction> hitAction)
{
    hitActions.push_back(hitAction);
}

const std::string &Creature::toString() const
{
    std::string str = Displayable::toString();
    str += "   hp: " + std::to_string(hp) + "\n";
    str += "   maxHit: " + std::to_string(hp) + "\n";
    
    str += "   items: \n";
    for (auto &it : items)
    {
        str += it.second->toString() + "\n";
    }

    //std::cout << str << std::endl;
    return str;
}