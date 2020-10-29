#ifndef ROOM_H_
#define ROOM_H_

#include <memory>
#include <iostream>
#include <string>

#include "../Displayable.hpp"

#include "Structure.hpp"

#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"

#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

class Room : public Structure
{
private:
    // Fields
    int width;
    int height;

    // Methods

public:
    // Constructors
    //using Structure::Structure;
    Room(const std::string &name);

    // Methods
    virtual int getHeight() const;
    virtual void setHeight(int height);

    virtual int getWidth() const;
    virtual void setWidth(int width);

    //void Room::initializeDisplay();

    virtual const std::string toString() const;

    // Operators

    // Destructor
};

#endif /* ROOM_H_ */