#include "Structure.hpp"

Structure::Structure(const std::string &name) : Displayable(name),
                                                supplementaryDisplayCode(' ')
{
}

void Structure::addMonster(const std::shared_ptr<Monster> monster)
{
    monsters.insert({monster->getName(), monster});
}

void Structure::addPlayer(const std::shared_ptr<Player> player)
{
    this->player = player;
}

std::shared_ptr<Player> Structure::getPlayer() const
{
    return player;
}

void Structure::addItem(const std::shared_ptr<Item> item)
{
    items.insert({item->getName(), item});
}

const GridObject &Structure::getSupplementaryDisplayCode() const
{
    return supplementaryDisplayCode;
}

const std::string &Structure::toString() const
{
    std::string str = Displayable::toString();
    str += "   player: " + player->toString() + "\n";

    str += "   monsters: \n";
    for (auto &it : monsters)
    {
        str += it.second->toString() + "\n";
    }

    str += "   items: \n";
    for (auto &it : items)
    {
        str += it.second->toString() + "\n";
    }
    return str;
}