#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>

#include "ObjectDisplayGrid.hpp"

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
    std::string name;
    //std::shared_ptr<ObjectDisplayGrid> grid;
    std::unordered_map<std::string, std::shared_ptr<Room>> rooms;
    std::unordered_map<std::string, std::shared_ptr<Passage>> passages;
    std::unordered_map<std::string, std::shared_ptr<Monster>> monsters;
    std::shared_ptr<Player> player;
    std::unordered_map<std::string, std::shared_ptr<Item>> items;


    // Methods

public:
    // Constructors
    Dungeon(const std::string &name, int gameWidth, int topHeight, int gameHeight, int bottomHeight);

    // Methods
    virtual void addRoom(const std::shared_ptr<Room> room);
    virtual void addPassage(const std::shared_ptr<Passage> passage);
    virtual void addMonster(const std::shared_ptr<Monster> monster);
    virtual void addPlayer(const std::shared_ptr<Player> player);
    virtual std::shared_ptr<Player> getPlayer() const; 
    virtual void addItem(const std::shared_ptr<Item> item);
    virtual const std::string toString() const; 
    //virtual const std::string getSummary() const; 
    // Operators

    // Destructor
};

#endif /* DUNGEON_H_ */
