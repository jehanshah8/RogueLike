#ifndef MONSTER_H_
#define MONSTER_H_

#include <memory>
#include <iostream>
#include <string>

#include "../Displayable.hpp"

#include "Creature.hpp"
#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

class Monster : public Creature
{
private:
    // Fields
    char type;

    // Methods

public:
    // Constructors
    using Creature::Creature; 
    
    // Methods
    virtual void setType(char type);

    virtual const std::string toString() const;

    // Operators

    // Destructor
};

#endif /* MONSTER_H_ */