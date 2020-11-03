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
    //std::vector<std::vector<char>> grid;

    // Methods

public:
    // Constructors
    ObjectDisplayGrid(const int gameHeight, const int gameWidth, const int topHeight, const int bottomHeight);

    // Methods

    virtual void addObjectToDisplay(const int row, const int col, const char gridChar);
    virtual void removeObjectFromDisplay(const int row, const int col);
    virtual void update();
    virtual void setTopMessage(int hitPoints = 0, int score = 0);
    virtual void setBottomMessagePack(const std::string &inventory = "none");
    virtual void setBottomMessageInfo(const std::string &message = "hello");
    //virtual char getDisplayable(const int row, const int col) const;
    //virtual int getGameHeight() const;
    //virtual int getGameWidth() const;
    //virtual int getTopHeight() const;
    //virtual int getBottomHeight() const;

    // Operators

    // Destructor
    virtual ~ObjectDisplayGrid();
};

#endif /* OBJECT_DISPLAY_GRID_H_ */