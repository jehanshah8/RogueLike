#ifndef DISPLAYABLE_H_
#define DISPLAYABLE_H_

#include <string>
#include <memory>
#include <iostream>
#include "inheritable_enable_shared_from_this.hpp"
class ObjectDisplayGrid;

class Displayable : public inheritable_enable_shared_from_this<Displayable>
{
protected:
    // Fields
    char displayCode;
    std::string name;
    bool isVisible;
    int posX;
    int posY;
    std::shared_ptr<ObjectDisplayGrid> grid;

public:
    // Constructors
    Displayable(const std::string &name = "newDisplayable", char displayCode = ' ');

    // Methods
    virtual const std::string &getName() const;
    virtual void setVisibility(int isVisible);
    virtual bool getVisibility() const;
    virtual void setPosX(int x);
    virtual int getPosX() const;
    virtual void setPosY(int y);
    virtual int getPosY() const;
    virtual char getDisplayCode() const;
    virtual void setDisplaycode(char displayCode);
    virtual void initializeDisplay();
    virtual void leaveGrid();
    virtual void printMessage(const std::string &msg);

    // below was not virtual upto addtion of sword and armor to battle in step 4
    virtual void setObjectDisplayGrid(const std::shared_ptr<ObjectDisplayGrid> grid);

    virtual const std::shared_ptr<ObjectDisplayGrid> getObjectDisplayGrid() const;

    virtual const std::string toString(int indentation = 0) const;

    // Operators

    // Destructor
    //virtual ~Displayable();
};

#endif /* DISPLAYABLE_H_ */