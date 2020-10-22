#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>

#include "../ObjectDisplayGrid.hpp"

#include "../Displayable.hpp"

#include "Structure.hpp"
#include "Room.hpp"
#include "Passage.hpp"

class Dungeon : public Structure
{
private:
    // Fields
    std::shared_ptr<ObjectDisplayGrid> grid;
    std::unordered_map<std::string, std::shared_ptr<Room>> rooms;
    std::unordered_map<std::string, std::shared_ptr<Passage>> passages;

    // Methods

public:
    // Constructors
    Dungeon(const std::string &name, const int gameWidth, const int topHeight, const int gameHeight, const int bottomHeight);

    // Methods
    virtual void addRoom(const std::shared_ptr<Room> room);
    virtual void addPassage(const std::shared_ptr<Passage> passage);

    // Operators

    // Destructor
};

#endif /* DUNGEON_H_ */
