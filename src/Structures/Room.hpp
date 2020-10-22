#ifndef ROOM_H_
#define ROOM_H_

#include <memory>
#include <iostream>
#include <string>

//#include "../ObjectDisplayGrid.hpp"
#include "../Displayable.hpp"

#include "Structure.hpp"

class Room : public Structure
{
private:
    // Fields
    int width;
    int height;

    // Methods

public:
    // Constructors
    using Structure::Structure; 

    // Methods
    virtual void setWidth(int width);
    virtual void setHeight(int height);

    // Operators

    // Destructor
};

#endif /* ROOM_H_ */