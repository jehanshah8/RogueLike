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

class Dungeon;

class Player : public Creature, public Observer
{
private:
    // Fields
    int hpMoves;
    std::vector<std::shared_ptr<Item>> items;
    //std::shared_ptr<Item> swordWeilded; 
    //std::shared_ptr<Item> armorWorn; 
    bool isWeildingSword;
    int swordBonus;
    bool isWearingArmor;
    int armorBonus;
    int moveCount; 
    std::queue<char> commandHistory;
    std::shared_ptr<KeyboardListener> keyboardListener;
    int score;
    std::shared_ptr<Dungeon> dungeon; 

    // Methods
    virtual const std::string toStringItems() const; 
    virtual void move(int dx, int dy);
    virtual void showPackContents();
    virtual void pickUpItem();
    //virtual void dropItem(char itemNum = 0);
    virtual void weildSword(char itemNum);
    virtual void wearArmor(char itemNum);
    virtual void takeOffArmor();
    virtual void readScroll(char itemNum);
    
    

public:
    // Constructors
    Player(const std::string &name, int room = -1, int serial = -1);

    // Methods
    virtual void setHpMoves(int hpMoves);
    virtual void setScore(int score);
    virtual const int getScore() const;
    virtual void addItem(const std::shared_ptr<Item> item);
    virtual void getHit(const std::shared_ptr<Creature> attacker, int damage);
    virtual void releaseAllItems();
    virtual const std::string toString() const;
    
    virtual void initializeDisplay();
    virtual void run(std::shared_ptr<KeyboardListener> keyboardListener); 

    virtual void update(char input); 
    virtual void dropItem(char itemNum);
    virtual void endGame();

    virtual const std::shared_ptr<Sword> getSwordWeilded() const;
    virtual const std::shared_ptr<Armor> getArmorWorn() const;
    virtual void setDungeon(const std::shared_ptr<Dungeon> dungeon);
    virtual const std::shared_ptr<KeyboardListener> getKeyboardListener() const;
    // Operators

    // Destructor
};

#endif /* PLAYER_H_ */