#ifndef ROOM_H_
#define ROOM_H_

#include "../Displayable.hpp"
#include "Structure.hpp"

#include <iostream>
#include <string>

class Room : public Structure {
    private:
    // Fields

    // Methods

    public:
    // Constructors
    Room(std::string _roomID);

    // Methods
    void setId(int roomID);
    void setCreature(Creature& monster);
    
    // Operators

    // Destructor
};

#endif /* ROOM_H_ */