#ifndef ROOM_H_
#define ROOM_H_

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

//#include "../ObjectDisplayGrid.hpp"
#include "../Displayable.hpp"

#include "Structure.hpp"

#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"

#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

class Room : public Structure {
    private:
    // Fields
  
    // Methods

    public:
    // Constructors
    Room(std::string _roomID);

    // Methods
    
    void setId(std::string roomId);

    void setCreature(Creature& monster);
    
    // Operators

    // Destructor
};

#endif /* ROOM_H_ */