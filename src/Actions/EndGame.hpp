#ifndef END_GAME_H_
#define END_GAME_H_

#include <string>

#include "Action.hpp"
#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"

class EndGame : public Action
{
private:
    // Fields

    // Methods
public:
    // Constructors
    EndGame();

    // Methods
    virtual void execute();

    // Operators

    // Destructor
};

#endif /* END_GAME_H_ */