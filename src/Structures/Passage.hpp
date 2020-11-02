#ifndef PASSAGE_H_
#define PASSAGE_H_

#include <memory>
#include <iostream>
#include <string>

#include "../Displayable.hpp"

#include "Structure.hpp"

#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"

#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

class Passage : public Structure
{
private:
    // Fields
    int room1;
    int room2;
    std::vector<std::array<int, 2>> path; 
    // Methods
public:
    // Constructors
    Passage(int room1, int room2);

    // Methods
    virtual void setPosX(int x);
    virtual int getPosX() const;
    virtual void setPosY(int y);
    virtual int getPosY() const;
    
    const std::string toString() const;

    // Operators

    // Destructor
};

#endif /* PASSAGE_H_ */