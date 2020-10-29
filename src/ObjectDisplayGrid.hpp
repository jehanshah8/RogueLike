#ifndef OBJECT_DISPLAY_GRID_H_
#define OBJECT_DISPLAY_GRID_H_

#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include <curses.h>

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
    
    virtual void addObjectToDisplay(const int row, const int col, const char displayObject); 
    virtual char getDisplayable(const int row, const int col) const; 
    virtual void removeObjectFromDisplay(const int row, const int col);
    virtual void setTopMessage(const int hitPoints, const int score); 
    virtual void setBottomMessage(const std::string& inventory, const std::string& message);
    virtual void update(const char input);
    virtual int getGameHeight() const; 
    virtual int getGameWidth() const; 
    virtual int getTopHeight() const; 
    virtual int getBottomHeight() const; 
    
    // Operators

    // Destructor
    virtual ~ObjectDisplayGrid();
};

#endif /* OBJECT_DISPLAY_GRID_H_ */