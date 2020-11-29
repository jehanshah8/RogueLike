#ifndef TELEPORT_H_
#define TELEPORT_H_

#include <string>

#include "Action.hpp"
#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"
#include "../ObjectDisplayGrid.hpp"

class Teleport : public Action
{
private:
    // Fields

    // Methods
public:
    // Constructors
    Teleport();

    // Methods
    virtual void execute();

    // Operators

    // Destructor
};

#endif /* TELEPORT_H_ */