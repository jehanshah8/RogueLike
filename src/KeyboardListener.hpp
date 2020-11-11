#ifndef KEYBOARD_LISTENER_H_
#define KEYBOARD_LISTENER_H_

#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <memory>
#include <thread>
#include <atomic>
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
    std::atomic_bool keepRunning;

    // Methods
    virtual void getInput();
    virtual void notifyObservers();

public:
    // Constructors
    KeyboardListener();

    // Methods
    virtual void registerObserver(std::shared_ptr<Observer> observer);
    virtual void removeObserver(std::shared_ptr<Observer> observer);
    virtual void run();
    virtual void kill();

    // Operators

    // Destructor
};

#endif /* KEYBOARD_LISTENER_H_ */