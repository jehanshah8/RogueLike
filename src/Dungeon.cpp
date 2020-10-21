#include "Dungeon.hpp"

Dungeon::Dungeon(const std::string& _name, const int _width, const int _topHeight, const int _gameHeight, const int _bottomHeight) {
    
    std::string str = "Dungeon: \n";
    str += "   name: " + _name + "\n";
    str += "   width: " + std::to_string(_width) + "\n";
    str += "   topHeight: " + std::to_string(_topHeight) + "\n"; 
    str += "   gameHeight: " + std::to_string(_gameHeight) + "\n";
    str += "   bottomHeight: " + std::to_string(_bottomHeight) + "\n";   
    
    std::cout << str << std::endl;
}

void Dungeon::addRoom(const std::shared_ptr<Room> room) {
    rooms.insert({room->getId(), room});
}

void Dungeon::addPassage(const std::shared_ptr<Passage> passage) {
    passages.insert({passage->getId(), passage});
}

void Dungeon::addCreature(const std::shared_ptr<Creature> creature) {

}
void Dungeon::addItem(const std::shared_ptr<Item> item) {

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