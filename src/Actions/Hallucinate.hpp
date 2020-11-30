#ifndef HALLUCINATE_H_
#define HALLUCINATE_H_

#include <string>

#include "Action.hpp"

#include "../Items/Item.hpp"
#include "../Items/Scroll.hpp"
#include "../Items/Armor.hpp"
#include "../Items/Sword.hpp"

#include "../ObjectDisplayGrid.hpp"

#include "../Observer.hpp"
#include "../KeyboardListener.hpp"
#include "../Creatures/Player.hpp"

class Hallucinate : public Action, public Observer
{
private:
    // Fields
    std::queue<char> commandHistory;
    std::shared_ptr<ObjectDisplayGrid> grid;
    std::shared_ptr<KeyboardListener> keyboardListener;

    // Methods
    virtual void updateGrid();
public:
    // Constructors
    Hallucinate();
    
    // Methods
    virtual void execute();
    virtual void update(char input);
    // Operators

    // Destructor
};

#endif /* HALLUCINATE_H_ */