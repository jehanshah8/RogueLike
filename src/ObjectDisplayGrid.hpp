#ifndef OBJECT_DISPLAY_GRID_H_
#define OBJECT_DISPLAY_GRID_H_

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <memory>

#include <curses.h>

//#include "Displayable.hpp"
//class Displayable;

class ObjectDisplayGrid
{
private:
    // Fields
    int gameHeight; 
    int gameWidth; 
    int topHeight; 
    int bottomHeight; 
    std::vector<std::vector<std::stack<char>>> grid;

    // Methods

public:
    // Constructors
    ObjectDisplayGrid(const int gameHeight, const int gameWidth, const int topHeight, const int bottomHeight);

    // Methods
    
    virtual void addObjectToDisplay(const int row, const int col, const char gridChar); 
    //virtual char getDisplayable(const int row, const int col) const; 
    //virtual void removeObjectFromDisplay(const int row, const int col);
    virtual void setTopMessage(const int hitPoints = 0, const int score = 0); 
    virtual void setBottomMessage(const std::string& inventory = "none", const std::string& message = "hello");
    virtual void update();
    //virtual int getGameHeight() const; 
    //virtual int getGameWidth() const; 
    //virtual int getTopHeight() const; 
    //virtual int getBottomHeight() const; 
    
    // Operators

    // Destructor
    virtual ~ObjectDisplayGrid();
};

#endif /* OBJECT_DISPLAY_GRID_H_ */