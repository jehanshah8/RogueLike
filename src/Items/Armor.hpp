#ifndef ARMOR_H_
#define ARMOR_H_

#include "Item.hpp"

class Armor : public Item {
    private:
    // Fields

    // Methods

    public:
    // Constructors
    Armor(std::string name);

    // Methods
    void setName(std::string name);
    void setID(int room, int serial);
    
    // Operators

    // Destructor
};

#endif /* ARMOR_H_ */