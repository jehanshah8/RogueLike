#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>
#include <iostream>
#include <string>

#include "../Displayable.hpp"

#include "Creature.hpp"
#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

class Player : public Creature
{
private:
    // Fields
    int hpMoves;

    // Methods

public:
    // Constructors
    Player(const std::string &name, int room = -1, int serial = -1);

    // Methods
    void setHpMoves(int hpMoves);

    virtual const std::string toString() const;

    // Operators

    // Destructor
};

#endif /* PLAYER_H_ */