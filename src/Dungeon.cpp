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

void Dungeon::addRoom(const Room& room) {

}

void Dungeon::addPassage(const Passage& passage) {

}

void Dungeon::addCreature(const Creature& creature) {

}

void Dungeon::addItem(const Item& item) {
    
}

std::string Dungeon::toString() {
    
}