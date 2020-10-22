#ifndef DISPLAYABLE_H_
#define DISPLAYABLE_H_

#include <string>

class Displayable
{
protected:
    // Fields
    std::string name;
    std::string id;
    bool isVisible;
    int posX;
    int posY;

public:
    // Constructors
    Displayable(const std::string &name);

    // Methods
    virtual std::string getName() const;
    virtual void setId(const int room = -1, const int serial = -1);
    virtual std::string getId() const;
    virtual void setVisibility(const int isVisible);
    virtual bool getVisibility() const;
    virtual void setPosX(const int x);
    virtual int getPosX() const;
    virtual void setPosY(const int y);
    virtual int getPosY() const;
    virtual std::string toString() const;
    // Operators

    // Destructor
};

#endif /* DISPLAYABLE_H_ */