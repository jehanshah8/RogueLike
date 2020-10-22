#include "Dungeon.hpp"

Dungeon::Dungeon(const std::string &name, const int gameWidth, const int topHeight, const int gameHeight, const int bottomHeight) : Structure(name)
{
    grid = std::make_shared<ObjectDisplayGrid>(gameHeight, gameWidth, topHeight, bottomHeight);
}

void Dungeon::addRoom(const std::shared_ptr<Room> room)
{
    rooms.insert({room->getName(), room});
}

void Dungeon::addPassage(const std::shared_ptr<Passage> passage)
{
    passages.insert({passage->getName(), passage});
}

/*
std::string Dungeon::toString() {
    std::string str = "Dungeon: \n";
    str += "   name: " + name + "\n";
    str += "   width: " + std::to_string(width) + "\n";
    str += "   topHeight: " + std::to_string(topHeight) + "\n"; 
    str += "   gameHeight: " + std::to_string(gameHeight) + "\n";
    str += "   bottomHeight: " + std::to_string(bottomHeight) + "\n";   
    
    std::cout << str << std::endl;
}
*/