#ifndef MONSTER_H_
#define MONSTER_H_

#include "Creature.hpp"
//#include "../Items/Item.hpp"

class Monster : public Creature {
    private:
    // Fields

    // Methods
    public:
    // Constructors
    Monster();

    // Methods
    virtual void setType(char type);
    void setName(std::string name);
    void setID(int room, int serial);

    // Operators

    // Destructor
};

#endif /* MONSTER_H_ */