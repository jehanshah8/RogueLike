#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer
{
public:
    virtual void update(char input) = 0;
};

#endif /* OBSERVER_H_ */