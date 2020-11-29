#ifndef BLESS_CURSE_OWNER_H_
#define BLESS_CURSE_OWNER_H_

#include <string>

#include "Action.hpp"

#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

#include "../Creatures/Player.hpp"

class BlessCurseOwner : public Action {
    private:
    // Fields

    // Methods
    public:
    // Constructors
    BlessCurseOwner();

    // Methods
    virtual void execute();
    
    // Operators

    // Destructor
};

#endif /* BLESS_CURSE_OWNER_H_ */