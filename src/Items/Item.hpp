#ifndef ITEM_H_
#define ITEM_H_

#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>

#include "../Displayable.hpp"
//#include "../Actions/Action.hpp"
//#include "../Actions/ItemActions/ItemAction.hpp"
//#include "../Actions/ItemActions/BlessCurseOwner.hpp"
//#include "../Actions/ItemActions/Hallucinate.hpp"

class Creature;
class Player;
class Monster;

class Item : public Displayable
{
private:
    // Fields
    int room;
    int serial;
    int itemIntValue;
    std::shared_ptr<Creature> owner;

    // Methods

public:
    // Constructors
    Item(const std::string &name, int room = -1, int serial = -1);

    // Methods
    virtual void setItemIntValue(const int value);
    virtual void setOwner(const std::shared_ptr<Creature> owner);

    virtual const std::string toString() const; 
    // Operators

    // Destructor
};

#endif /* ITEM_H_ */