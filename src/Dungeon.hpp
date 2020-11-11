#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>
#include <atomic> 
#include <thread>

#include "Observer.hpp"
#include "KeyboardListener.hpp"

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

class Dungeon : public std::enable_shared_from_this<Dungeon>, public Observer
{

private:
    // Fields
    std::string name;
    int gameHeight; 
    int gameWidth; 
    int topHeight; 
    int bottomHeight; 

    std::vector<std::shared_ptr<Room>> rooms;
    std::vector<std::shared_ptr<Passage>> passages;
    std::vector<std::shared_ptr<Monster>> monsters;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Item>> items;

    std::shared_ptr<KeyboardListener> keyboardListener;
    std::shared_ptr<ObjectDisplayGrid> grid;
    //std::atomic_bool isRunning;


    // Methods
    void initializeGrid();

public:
    // Constructors
    Dungeon(const std::string &name, int gameWidth, int topHeight, int gameHeight, int bottomHeight);

    // Methods
    virtual void startGame(); 
    virtual int getGameHeight() const; 
    virtual int getGameWidth() const;
    virtual int getTopHeight() const;
    virtual int getBottomHeight() const;

    virtual void update(char input); 

    virtual const std::vector<std::shared_ptr<Room>> getRooms() const; 
    virtual void addRoom(const std::shared_ptr<Room> room);

    virtual const std::vector<std::shared_ptr<Passage>> getPassages() const; 
    virtual void addPassage(const std::shared_ptr<Passage> passage);

    virtual void addMonster(const std::shared_ptr<Monster> monster);

    virtual std::shared_ptr<Player> getPlayer() const;
    virtual void addPlayer(const std::shared_ptr<Player> player);

    virtual void addItem(const std::shared_ptr<Item> item);

    virtual void endGame();

    virtual const std::string toString() const; 

    // Operators

    // Destructor
};

#endif /* DUNGEON_H_ */
