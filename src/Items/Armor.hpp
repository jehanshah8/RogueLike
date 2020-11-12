#ifndef ARMOR_H_
#define ARMOR_H_

#include "Item.hpp"

class Armor : public Item
{
private:
    // Fields

    // Methods

public:
    // Constructors
    Armor(const std::string &name, int room = -1, int serial = -1);

    // Methods
    virtual void equip();

    // Operators

    // Destructor
};

#endif /* ARMOR_H_ */