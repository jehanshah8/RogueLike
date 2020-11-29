#ifndef ACTION_H_
#define ACTION_H_

#include <iostream>
#include <string>


#include "../Creatures/Creature.hpp"
#include "../Items/Item.hpp"

class Action
{
protected:
    // Fields
    std::string message;
    int intValue;
    char charValue;
    std::shared_ptr<Displayable> owner;

    // Methods
public:
    // Constructors
    Action();

    // Methods
    virtual void execute() = 0;
    virtual void setMessage(const std::string &message);
    virtual void setInValue(int value);
    virtual void setCharValue(char value);
    virtual void setOwner(const std::shared_ptr<Displayable> owner);

    // Operators

    // Destructor
};

#endif /* ACTION_H_ */