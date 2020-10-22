#ifndef PASSAGE_H_
#define PASSAGE_H_

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

class Passage : public Structure
{
private:
    // Fields
    int room1;
    int room2;

    // Methods
public:
    // Constructors
    Passage(const int room1, const int room2); 
    // Methods

    // Operators

    // Destructor
};

#endif /* PASSAGE_H_ */