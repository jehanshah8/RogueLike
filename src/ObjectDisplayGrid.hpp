#ifndef OBJECT_DISPLAY_GRID_H_
#define OBJECT_DISPLAY_GRID_H_

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <memory>

#include <curses.h>
#include "Displayable.hpp"

class ObjectDisplayGrid
{
private:
    // Fields
    int gameHeight;
    int gameWidth;
    int topHeight;
    int bottomHeight;
    std::vector<std::vector<std::stack<std::shared_ptr<Displayable>>>> objectGrid; 
    bool keepRunning; 
    
    // Methods

public:
    // Constructors
    ObjectDisplayGrid(int gameHeight, int gameWidth, int topHeight, int bottomHeight);

    // Methods
    virtual void addObjectToDisplay(int x, int y, const std::shared_ptr<Displayable> displayable);
    virtual void removeObjectFromDisplay(int x, int y);
    virtual const std::shared_ptr<Displayable> getDisplayable(int x, int y) const;
    virtual void update();
    virtual void setTopMessage(int hitPoints = 0, int score = 0);
    virtual void setBottomMessage1(const std::string &message = "");
    virtual void setBottomMessage2(const std::string &message = "");

    virtual void removeAllObjects();
    
    
    virtual const int getGameHeight() const;
    virtual const int getGameWidth() const;
    //virtual int getTopHeight() const;
    //virtual int getBottomHeight() const;

    // Operators

    // Destructor
    virtual ~ObjectDisplayGrid();
};

#endif /* OBJECT_DISPLAY_GRID_H_ */