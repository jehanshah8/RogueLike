#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "inheritable_enable_shared_from_this.hpp"

class Observer : public inheritable_enable_shared_from_this<Observer>
{
public:
    virtual void update(char input) = 0;
};

#endif /* OBSERVER_H_ */