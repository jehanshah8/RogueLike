#ifndef YOU_WIN_H_
#define YOU_WIN_H_

#include <string>

#include "Action.hpp"
#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"

class YouWin : public Action
{
private:
    // Fields

    // Methods
public:
    // Constructors
    YouWin();

    // Methods
    virtual void execute();

    // Operators

    // Destructor
};

#endif /* YOU_WIN_H_ */