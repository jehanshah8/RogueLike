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

    // Methods

public:
    // Constructors
    Monster(const std::string &name, int room = -1, int serial = -1);  
    
    // Methods
    virtual void setType(char type);
    virtual void getHit(const std::shared_ptr<Creature> attacker, int damage);

    virtual const std::string toString() const;

    // Operators

    // Destructor
};

#endif /* MONSTER_H_ */