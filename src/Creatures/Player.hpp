#ifndef PLAYER_H_
#define PLAYER_H_

#include "Creature.hpp"
#include "../Items/Item.hpp"
#include "../Items/Sword.hpp"
#include "../Items/Armor.hpp"

class Player : public Creature {
    private:
    // Fields

    // Methods
    public:
    // Constructors
    Player();

    // Methods
    void setWeapon(/**Item& sword*/);
    void setArmor(/**Item& armor*/);

    // Operators

    // Destructor
};

#endif /* PLAYER_H_ */