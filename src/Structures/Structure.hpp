#ifndef STRUCTURE_H_
#define STRUCTURE_H_

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "../Displayable.hpp"

#include "../Creatures/Creature.hpp"
#include "../Creatures/Player.hpp"
#include "../Creatures/Monster.hpp"

#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

class Structure : public Displayable
{
private:
protected:
    char supplementaryDisplayCode;
    std::unordered_map<std::string, std::shared_ptr<Monster>> monsters;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Item>> items;
    //std::unordered_map<std::string, std::shared_ptr<Item>> items;

    virtual const std::string toStringPlayer() const;
    virtual const std::string toStringMonsters() const;
    virtual const std::string toStringItems() const;

public:
    // Constructors
    Structure(const std::string &name, char displayCode, char supplementaryDisplayCode);

    // Methods
    virtual void addMonster(const std::shared_ptr<Monster> monster);
    virtual void addPlayer(const std::shared_ptr<Player> player);
    virtual std::shared_ptr<Player> getPlayer() const;
    virtual void addItem(const std::shared_ptr<Item> item);
    virtual const char getSupplementaryDisplayCode() const;

    virtual const std::string toString() const;

    // Operators

    // Destructor
};

#endif /* STRUCTURE_H_ */