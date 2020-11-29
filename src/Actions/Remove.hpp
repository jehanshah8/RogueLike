#ifndef REMOVE_H_
#define REMOVE_H_

#include <string>

#include "Action.hpp"
#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"

class Remove : public Action
{
private:
    // Fields

    // Methods
public:
    // Constructors
    Remove();

    // Methods
    virtual void execute();

    // Operators

    // Destructor
};

#endif /* REMOVE_H_ */