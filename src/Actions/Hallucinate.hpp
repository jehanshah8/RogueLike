#ifndef HALLUCINATE_H_
#define HALLUCINATE_H_

#include <string>

#include "Action.hpp"

#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

class Hallucinate : public Action
{
private:
    // Fields

    // Methods
public:
    // Constructors
    Hallucinate();

    // Methods
    virtual void execute();
    // Operators

    // Destructor
};

#endif /* HALLUCINATE_H_ */