#ifndef KEYBOARD_LISTENER_H_
#define KEYBOARD_LISTENER_H_

#include <iostream>
#include <string>
#include <memory>

#include "ObjectDisplayGrid.hpp"
#include "Displayable.hpp"

#include "Structures/Structure.hpp"
#include "Structures/Dungeon.hpp"
#include "Structures/Room.hpp"
#include "Structures/Passage.hpp"

#include "Creatures/Creature.hpp"
#include "Creatures/Player.hpp"

class KeyboardListener {
private:
    // Fields
    std::shared_ptr<ObjectDisplayGrid> grid;
    bool isRunning = false;
    
    // Methods

public:
    // Constructors
    KeyboardListener(const std::shared_ptr<ObjectDisplayGrid> grid, const std::shared_ptr<Dungeon> dungeon);
    
    // Methods
    void run();

    // Operators

    // Destructor
};

#endif /* KEYBOARD_LISTENER_H_ */