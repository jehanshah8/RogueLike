#ifndef ACTION_H_
#define ACTION_H_

#include "../Creatures/Creature.hpp"

#include <iostream>
#include <string>

class Action {
    private:
    // Fields

    // Methods
    public:
    // Constructors
    Action();

    // Methods
    void setMessage(std::string message);
    void setInValue(int value);
    void setCharValue(char value);

    // Operators

    // Destructor
};

#endif /* ACTION_H_ */