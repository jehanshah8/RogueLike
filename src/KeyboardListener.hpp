#ifndef KEYBOARD_LISTENER_H_
#define KEYBOARD_LISTENER_H_

#include <memory>
#include "ObjectDisplayGrid.hpp"

class KeyboardListener {
private:
    // Fields
    std::shared_ptr<ObjectDisplayGrid> grid;
    bool isRunning = false;
    
    // Methods

public:
    // Constructors
    KeyboardListener(std::shared_ptr<ObjectDisplayGrid> grid);
    
    // Methods
    void run();

    // Operators

    // Destructor
};

#endif /* KEYBOARD_LISTENER_H_ */