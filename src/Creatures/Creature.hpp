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

class Action;

class Creature : public Displayable
{
protected:
    int room;
    int serial;
    int hp;
    int maxHit;
    bool isAlive;

    //std::unordered_map<std::string, std::shared_ptr<Item>> items;
    std::vector<std::shared_ptr<Action>> deathActions;
    std::vector<std::shared_ptr<Action>> hitActions;

public:
    // Constructors
    Creature(const std::string &name, char displayCode, int room = -1, int serial = -1);

    // Methods
    virtual void setHp(int hp);
    virtual void setMaxHit(int maxHit);
    virtual void addDeathAction(const std::shared_ptr<Action> action);
    virtual void addHitAction(const std::shared_ptr<Action> action);
    virtual void getHit(const std::shared_ptr<Creature> attacker, int damage) = 0;
    virtual void initializeDisplay();
    virtual const std::string toString() const;
    virtual const bool getIsAlive() const;
    // for actions
    virtual void releaseAllActions();
    virtual void updateGrid();

    // Operators

    // Destructor
};

#endif /* CREATURE_H_ */