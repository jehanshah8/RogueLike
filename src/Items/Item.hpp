#ifndef ITEM_H_
#define ITEM_H_

#include "../Displayable.hpp"
#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"

#include <iostream>
#include <string>

class Item : public Displayable {
    private:
    // Fields

    // Methods
    public:
    // Constructors
    Item();

    // Methods
    void setOwner(Creature& owner);

    // Operators

    // Destructor
};

#endif /* ITEM_H_ */