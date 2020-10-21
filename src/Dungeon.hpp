#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "ObjectDisplayGrid.hpp"

#include "Displayable.hpp"

#include "Structures/Structure.hpp"
#include "Structures/Room.hpp"
#include "Structures/Passage.hpp"

#include "Creatures/Creature.hpp"
#include "Creatures/Player.hpp"
#include "Creatures/Monster.hpp"

#include "Items/Item.hpp"
#include "Items/Scroll.hpp"
#include "Items/Armor.hpp"
#include "Items/Sword.hpp"

class Dungeon
{
private:
    // Fields
    std::string id; 
    std::shared_ptr<ObjectDisplayGrid> grid;
    std::unordered_map<std::string, std::shared_ptr<Room>> rooms;
    std::unordered_map<std::string, std::shared_ptr<Passage>> passages;
    std::unordered_map<std::string, std::shared_ptr<Monster>> monsters;
    std::shared_ptr<Player> player; 
    std::unordered_map<std::string, std::shared_ptr<Item>> items;
    // Methods

public:
    // Constructors
    Dungeon(const std::string &_name, const int _width, const int _topHeight, const int _gameHeight, const int _bottomHeight);

    // Methods
    //virtual Dungeon& getDungeon(const std::string& name, const int width, const int gameHeight) const;
    virtual void addRoom(const std::shared_ptr<Room> room);
    virtual void addPassage(const std::shared_ptr<Passage> passage);
    virtual void addCreature(const std::shared_ptr<Creature> creature);
    virtual void addItem(const std::shared_ptr<Item> item);
    virtual std::string toString();
    // Operators

    // Destructor
};

#endif /* DUNGEON_H_ */
