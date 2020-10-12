#ifndef ROOM_H_
#define ROOM_H_

#include "Structure.hpp"

class Room : public Structure {
    private:
    // Fields

    // Methods

    public:
    // Constructors
    Room(std::string room);

    // Methods
    void setId(int room);
    void setCreature(/**Creature& monster*/);
    
    // Operators

    // Destructor
};

#endif /* ROOM_H_ */