#ifndef CREATURE_H_
#define CREATURE_H_

#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../Displayable.hpp"

#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

//#include "../Actions/Action.hpp"
//#include "../Actions/CreatureActions/CreatureAction.hpp"
//#include "../Actions/CreatureActions/Remove.hpp"
//#include "../Actions/CreatureActions/YouWin.hpp"
//#include "../Actions/CreatureActions/UpdateDisplay.hpp"
//#include "../Actions/CreatureActions/Teleport.hpp"
//#include "../Actions/CreatureActions/ChangeDisplayedType.hpp"
//#include "../Actions/CreatureActions/EndGame.hpp"
//#include "../Actions/CreatureActions/DropPack.hpp"

//class Item;
//class Scroll;
//class Armor;
//class Sword;

//class Action;
class CreatureAction;

class Creature : public Displayable
{
protected:
    int room;
    int serial;
    int hp;
    int maxHit;
    
    //std::unordered_map<std::string, std::shared_ptr<Item>> items;
    std::vector<std::shared_ptr<CreatureAction>> deathActions;
    std::vector<std::shared_ptr<CreatureAction>> hitActions;

public:
    // Constructors
    Creature(const std::string &name, char displayCode, int room = -1, int serial = -1);

    // Methods
    virtual void setHp(int hp);
    virtual void setMaxHit(int maxHit);
    virtual void addDeathAction(const std::shared_ptr<CreatureAction> deathAction);
    virtual void addHitAction(const std::shared_ptr<CreatureAction> hitAction);

    virtual const std::string toString() const; 
    // Operators

    // Destructor
};

#endif /* CREATURE_H_ */