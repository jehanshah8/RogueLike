#include "Dungeon.hpp"

Dungeon::Dungeon(const std::string &name, int gameWidth, int topHeight, int gameHeight, int bottomHeight) : name(name)
{
    //grid = std::make_shared<ObjectDisplayGrid>(gameHeight, gameWidth, topHeight, bottomHeight);
}

void Dungeon::addRoom(const std::shared_ptr<Room> room)
{
    rooms.push_back(room);
}

void Dungeon::addPassage(const std::shared_ptr<Passage> passage)
{
    passages.push_back(passage);
}

void Dungeon::addMonster(const std::shared_ptr<Monster> monster)
{
    monsters.push_back(monster);
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
    items.push_back(item);
}

const std::string Dungeon::toString() const
{
    std::string str = "\tDungeon: \n";
    str += "\tname: " + name + "\n";
    //str += "   gameHeight: " + std::to_string(grid->getGameHeight()) + "\n";
    //str += "   gameWidth: " + std::to_string(grid->getGameWidth()) + "\n";
    //str += "   topHeight: " + std::to_string(grid->getTopHeight()) + "\n";
    //str += "   bottomHeight: " + std::to_string(grid->getBottomHeight()) + "\n";

    str += "\trooms in the dungeon: \n";
    for (auto &it : rooms)
    {
        str += it->toString() + "\n";
    }

    str += "\tpassages in the dungeon: \n";
    for (auto &it : passages)
    {
        str += it->toString() + "\n";
    }

    return str;
}

/*
const std::string Dungeon::getSummary() const
{
    std::string str = "Dungeon: \n";
    str += "   name: " + name + "\n";
    //str += "   gameHeight: " + std::to_string(grid->getGameHeight()) + "\n";
    //str += "   gameWidth: " + std::to_string(grid->getGameWidth()) + "\n";
    //str += "   topHeight: " + std::to_string(grid->getTopHeight()) + "\n";
    //str += "   bottomHeight: " + std::to_string(grid->getBottomHeight()) + "\n";
    
    std::cout <<"here" << std::endl; 
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

    //std::cout << str << std::endl;
    return str;
}
*/