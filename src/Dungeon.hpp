#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <iostream>
#include <string>
#include <vector>

class Dungeon {
    private:
    // Fields

    // Methods

    public:

    // Constructors
    Dungeon(); 

    // Methods
    void getDungeon(std::string name, int width, int gameHeight);
    void addRoom(/**Room& room*/);
    void addCreature(/**Creature& creature*/);
    void addPassage(/**Passage& passage*/);
    void addItem(/**Item& item*/); 

    // Operators

    // Destructor

};

#endif /* DUNGEON_H_ */

