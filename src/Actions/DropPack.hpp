#ifndef DROP_PACK_H_
#define DROP_PACK_H_

#include <string>

#include "Action.hpp"
#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"

class DropPack : public Action
{
private:
    // Fields

    // Methods
public:
    // Constructors
    DropPack();

    // Methods
    virtual void execute();

    // Operators

    // Destructor
};

#endif /* DROP_PACK_H_ */