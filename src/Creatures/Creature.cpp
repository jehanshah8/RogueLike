#include "Creature.hpp"
#include "../ObjectDisplayGrid.hpp"
#include "../Actions/Action.hpp"

Creature::Creature(const std::string &name, char displayCode, int room, int serial) : Displayable(name, displayCode),
                                                                                      room(room),
                                                                                      serial(serial),
                                                                                      isAlive(true)
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

void Creature::addDeathAction(const std::shared_ptr<Action> action)
{
    deathActions.push_back(action);
    action->setOwner(Displayable::downcasted_shared_from_this<Creature>());
}

void Creature::addHitAction(const std::shared_ptr<Action> action)
{
    hitActions.push_back(action);
    action->setOwner(Displayable::downcasted_shared_from_this<Creature>());
}

void Creature::initializeDisplay()
{
    Displayable::initializeDisplay();
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

void Creature::updateGrid()
{
    grid->update();
}

const bool Creature::getIsAlive() const
{
    return isAlive;
}

void Creature::releaseAllActions()
{
    for (auto &it : hitActions)
    {
        it->setOwner(nullptr);
    }

    for (auto &it : deathActions)
    {
        it->setOwner(nullptr);
    }
}