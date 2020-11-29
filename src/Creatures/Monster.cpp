#include "Monster.hpp"
#include "../ObjectDisplayGrid.hpp"
#include "../Actions/Action.hpp"

Monster::Monster(const std::string &name, int room, int serial) : Creature(name, 'M', room, serial)
{
    //std::cout << "creating monster" << std::endl;
}

void Monster::setType(char type)
{
    //this->type = type;
    displayCode = type;
}

void Monster::getHit(const std::shared_ptr<Creature> attacker, int damage)
{
    hp -= damage;
    std::string str = "Info: Hit " + name + "; damage: " + std::to_string(damage);
    grid->setBottomMessage1(str);
    grid->update();

    if (hp <= 0)
    {
        isAlive = false;

        //
        //grid->setBottomMessage1(std::to_string(deathActions.size()));
        //grid->update();
        //
        //while(true);
        for (auto &it : deathActions)
        {
            it->execute();
        }
        Creature::releaseAllActions();
        // pre-actions
        //grid->removeObjectFromDisplay(posX, posY);
        //grid->setBottomMessage1("Info: Killed " + name + ".");
        //grid->update();
    }
    else
    {
        int returnDamage = rand() % (maxHit + 1);
        attacker->getHit(nullptr, returnDamage);

        for (auto &it : hitActions)
        {
            it->execute();
        }
    }
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