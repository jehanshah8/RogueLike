#ifndef CREATURE_H_
#define CREATURE_H_

#include "../Displayable.hpp"
#include "../Actions/CreatureActions/CreatureAction.hpp"

#include <iostream>
#include <string>

class Creature : public Displayable {
    private:
    // Fields

    // Methods
    public:
    // Constructors
    Creature();

    // Methods
    void setHp(int h);
    void setHpMoves(int hpMoves);
    void setDeathAction(/**CreatureAction& deathAction*/);
    void setHitAction(/**CreatureAction& hitAction*/);

    // Operators

    // Destructor
};

#endif /* CREATURE_H_ */