#ifndef UPDATE_DISPLAY_H_
#define UPDATE_DISPLAY_H_

#include <string>

#include "Action.hpp"
#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"

class UpdateDisplay : public Action
{
private:
    // Fields

    // Methods
public:
    // Constructors
    UpdateDisplay();

    // Methods
    virtual void execute();

    // Operators

    // Destructor
};

#endif /* UPDATE_DISPLAY_H_ */