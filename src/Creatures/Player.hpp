#ifndef PLAYER_H_
#define PLAYER_H_

#include "Creature.hpp"
#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

class Player : public Creature {
    private:
    // Fields

    // Methods
    public:
    // Constructors
    Player();

    // Methods
    void setHpMoves(int hpMoves);
    void setWeapon(/**Item& sword*/);
    void setArmor(/**Item& armor*/);

    // Operators

    // Destructor
};

#endif /* PLAYER_H_ */