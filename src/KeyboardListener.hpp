#ifndef KEYBOARD_LISTENER_H_
#define KEYBOARD_LISTENER_H_

#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <memory>
#include <thread>
#include <unordered_set>
#include <queue>

#include "Subject.hpp"
#include "Observer.hpp"

class KeyboardListener //: public Subject
{
private:
    // Fields
    std::vector<std::shared_ptr<Observer>> observers;
    //std::unordered_set<std::shared_ptr<Observer>> observers;
    std::queue<char> commandHistory;
    bool keepRunning;

    // Methods
    //void getInput();
public:
    // Constructors
    KeyboardListener();

    // Methods
    virtual void registerObserver(std::shared_ptr<Observer> observer);
    virtual void removeObserver(std::shared_ptr<Observer> observer);
    virtual void notifyObservers();
    virtual void run();
    virtual void kill();

    // Operators

    // Destructor
};

#endif /* KEYBOARD_LISTENER_H_ */