#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>
#include <iostream>
#include <string>
#include <queue>

#include "../Displayable.hpp"

#include "../Observer.hpp"
#include "../KeyboardListener.hpp"

#include "Creature.hpp"
#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

class Player : public Creature, public Observer
{
private:
    // Fields
    int hpMoves;
    std::vector<std::shared_ptr<Item>> items;
    std::queue<char> commandHistory;
    std::shared_ptr<KeyboardListener> keyboardListener;

    // Methods
    virtual const std::string toStringItems() const; 
    virtual void move(int dx, int dy);
    virtual void showPackContents();
    virtual void pickUpItem();
    virtual void dropItem(char itemNum);

public:
    // Constructors
    Player(const std::string &name, int room = -1, int serial = -1);

    // Methods
    void setHpMoves(int hpMoves);
    virtual void addItem(const std::shared_ptr<Item> item);
    virtual const std::string toString() const;
    
    virtual void initializeDisplay();
    virtual void run(std::shared_ptr<KeyboardListener> keyboardListener); 

    virtual void update(char input); 

    // Operators

    // Destructor
};

#endif /* PLAYER_H_ */