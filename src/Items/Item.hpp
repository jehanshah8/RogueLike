#ifndef ITEM_H_
#define ITEM_H_

#include <memory>
#include <iostream>
#include <string>

#include "../Displayable.hpp"
#include "../Actions/Action.hpp"
#include "../Actions/ItemActions/ItemAction.hpp"
#include "../Actions/ItemActions/BlessCurseOwner.hpp"
#include "../Actions/ItemActions/Hallucinate.hpp"

//#include "../Creatures/Creature.hpp"
//#include "../Creatures/Player.hpp"
//#include "../Creatures/Monster.hpp"

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
    Item(const std::string &name, const int room, const int serial);

    // Methods
    virtual void setItemIntValue(const int value);
    virtual void setOwner(const std::shared_ptr<Creature> owner);

    // Operators

    // Destructor
};

#endif /* ITEM_H_ */