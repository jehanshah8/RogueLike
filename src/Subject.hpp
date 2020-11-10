#ifndef SUBJECT_H_
#define SUBJECT_H_

class Subject
{
public:
    Subject();
    virtual void registerObserver() = 0;
    virtual void removeObserver() = 0;
    virtual void notifyObservers() = 0;
};

#endif /* SUBJECT_H_ */