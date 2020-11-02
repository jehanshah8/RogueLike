#ifndef SWORD_H_
#define SWORD_H_

#include "Item.hpp"

class Sword : public Item
{
private:
    // Fields

    // Methods

public:
    // Constructors
    Sword(const std::string &name, int room = -1, int serial = -1);

    // Methods

    // Operators

    // Destructor
};

#endif /* SWORD_H_ */