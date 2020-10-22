#include "Structure.hpp"

void Structure::addMonster(const std::shared_ptr<Monster> monster)
{
    monsters.insert({monster->getName(), monster});
}

void Structure::addPlayer(const std::shared_ptr<Player> player)
{
    this->player = player;
}

void Structure::addItem(const std::shared_ptr<Item> item)
{
    items.insert({item->getName(), item});
}
