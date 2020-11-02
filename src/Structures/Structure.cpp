#include "Structure.hpp"

Structure::Structure(const std::string &name, char displayCode, char supplementaryDisplayCode) : Displayable(name, displayCode),
                                                                                                 supplementaryDisplayCode(supplementaryDisplayCode)
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
    items.push_back(item);
}

const char Structure::getSupplementaryDisplayCode() const
{
    return supplementaryDisplayCode;
}

const std::string Structure::toStringPlayer() const
{
    std::string str;
    if (player != nullptr)
    {
        str += player->toString() + "\n";
    }
    else
    {
        str += "\t\t\tno player here\n";
    }
    return str;
}

const std::string Structure::toStringMonsters() const
{
    std::string str;
    if (monsters.empty())
    {
        str += "\t\t\tno monsters here\n";
    }
    else
    {
        for (auto &it : monsters)
        {
            str += it.second->toString() + "\n";
        }
    }

    return str;
}

const std::string Structure::toStringItems() const
{
    std::string str;
    if (items.empty())
    {
        str += "\t\t\tno items here\n";
    }
    else
    {
        for (auto &it : items)
        {
            str += it->toString() + "\n";
        }
    }

    return str;
}

const std::string Structure::toString() const
{
    std::string str = Displayable::toString(2);
    return str;
}