#ifndef SWORD_H_
#define SWORD_H_

#include "Item.hpp"

class Sword : public Item {
    private:
    // Fields

    // Methods

    public:
    // Constructors
    Sword(std::string name);

    // Methods
    void setID(int room, int serial);
    
    // Operators

    // Destructor
};

#endif /* SWORD_H_ */