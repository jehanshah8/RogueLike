#ifndef CHANGE_DISPLAYED_TYPE_H_
#define CHANGE_DISPLAYED_TYPE_H_

#include <string>

#include "Action.hpp"
#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"

class ChangeDisplayedType : public Action
{
private:
    // Fields

    // Methods
public:
    // Constructors
    ChangeDisplayedType();

    // Methods
    virtual void execute();

    // Operators

    // Destructor
};

#endif /* CHANGE_DISPLAYED_TYPE_H_ */