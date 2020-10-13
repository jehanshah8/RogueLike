#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <memory>
#include <vector>
#include <iostream>
#include <string>

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

class Dungeon {
    private:
    // Fields
    std::vector<std::unique_ptr <Room> >rooms;
    std::vector<std::unique_ptr <Passage> >passages; 

    // Methods

    public:
    // Constructors
    Dungeon(const std::string& _name, const int _width, const int _topHeight, const int _gameHeight, const int _bottomHeight); 

    // Methods
    //virtual Dungeon& getDungeon(const std::string& name, const int width, const int gameHeight) const;
    virtual void addRoom(const Room& room);
    virtual void addPassage(const Passage& passage);
    virtual void addCreature(const Creature& creature);
    virtual void addItem(const Item& item); 
    virtual std::string toString();
    // Operators

    // Destructor

};

#endif /* DUNGEON_H_ */

