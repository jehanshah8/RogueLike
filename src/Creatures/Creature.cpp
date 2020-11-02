#include "Creature.hpp"

Creature::Creature(const std::string &name, char displayCode, int room, int serial) : Displayable(name, displayCode),
                                                                                      room(room),
                                                                                      serial(serial)
{
    //std::cout << "creating creature" << std::endl;
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

const std::string Creature::toString() const
{
    std::string str = Displayable::toString(3);
    str += "\t\t\troom: " + std::to_string(room) + "\n";
    str += "\t\t\tserial: " + std::to_string(serial) + "\n";
    str += "\t\t\thp: " + std::to_string(hp) + "\n";
    str += "\t\t\tmaxHit: " + std::to_string(maxHit) + "\n";

    return str;
}