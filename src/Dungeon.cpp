#include "Dungeon.hpp"

Dungeon::Dungeon(const std::string &name, int gameWidth, int topHeight, int gameHeight, int bottomHeight) : name(name)
{
    //grid = std::make_shared<ObjectDisplayGrid>(gameHeight, gameWidth, topHeight, bottomHeight);
}

void Dungeon::addRoom(const std::shared_ptr<Room> room)
{
    //std::cout<<"adding room"<<std::endl;
    rooms.insert({room->getName(), room});

    /*
    for (auto &it : rooms)
    {
        std::cout<<it.second->toString() << std::endl;
    }
    */
}

void Dungeon::addPassage(const std::shared_ptr<Passage> passage)
{
    passages.insert({passage->getName(), passage});
}

void Dungeon::addMonster(const std::shared_ptr<Monster> monster)
{
    monsters.insert({monster->getName(), monster});
}

void Dungeon::addPlayer(const std::shared_ptr<Player> player)
{
    this->player = player;
}

std::shared_ptr<Player> Dungeon::getPlayer() const
{
    return player;
}
void Dungeon::addItem(const std::shared_ptr<Item> item)
{
    items.insert({item->getName(), item});
}

const std::string Dungeon::toString() const
{
    std::string str = "Dungeon: \n";
    str += "   name: " + name + "\n";
    //str += "   gameHeight: " + std::to_string(grid->getGameHeight()) + "\n";
    //str += "   gameWidth: " + std::to_string(grid->getGameWidth()) + "\n";
    //str += "   topHeight: " + std::to_string(grid->getTopHeight()) + "\n";
    //str += "   bottomHeight: " + std::to_string(grid->getBottomHeight()) + "\n";

    str += "   rooms: \n";
    for (auto &it : rooms)
    {
        str += it.second->toString() + "\n";
    }

    str += "   passages: \n";
    for (auto &it : passages)
    {
        str += it.second->toString() + "\n";
    }

    std::cout << str << std::endl;
    return str;
}

const std::string Dungeon::toStringAll() const
{
    std::string str = "Dungeon: \n";
    str += "   name: " + name + "\n";
    //str += "   gameHeight: " + std::to_string(grid->getGameHeight()) + "\n";
    //str += "   gameWidth: " + std::to_string(grid->getGameWidth()) + "\n";
    //str += "   topHeight: " + std::to_string(grid->getTopHeight()) + "\n";
    //str += "   bottomHeight: " + std::to_string(grid->getBottomHeight()) + "\n";
    /*
    str += "   rooms: \n";
    for (auto &it : rooms)
    {
        str += it.second->toString() + "\n";
    }

    str += "   passages: \n";
    for (auto &it : passages)
    {
        str += it.second->toString() + "\n";
    }
    
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
    */
    //std::cout << str << std::endl;
    return str;
}