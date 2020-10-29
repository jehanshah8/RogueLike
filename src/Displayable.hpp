#ifndef DISPLAYABLE_H_
#define DISPLAYABLE_H_

#include <string>
#include <memory>

//#include "ObjectDisplayGrid.hpp"
#include "GridObject.hpp"

class Displayable
{
protected:
    // Fields 
    GridObject displayCode;
    std::string name;
    //std::string id;
    bool isVisible;
    int posX;
    int posY;
    //std::shared_ptr<ObjectDisplayGrid> grid;  

public:
    // Constructors
    Displayable(const std::string &name);

    // Methods
    virtual const std::string& getName() const;
    //virtual void setId(int room = -1, int serial = -1);
    //virtual const std::string& getId() const;
    virtual void setVisibility(int isVisible);
    virtual bool getVisibility() const;
    virtual void setPosX(int x);
    virtual int getPosX() const;
    virtual void setPosY(int y);
    virtual int getPosY() const;
    virtual const GridObject& getDisplayCode() const; 
    //virtual void setDisplayGrid(std::shared_ptr<ObjectDisplayGrid> grid); 
    //virtual void initializeDisplay(); 
     
    virtual const std::string& toString() const;
    // Operators

    // Destructor
};

#endif /* DISPLAYABLE_H_ */