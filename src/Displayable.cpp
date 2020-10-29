#include "Displayable.hpp"

Displayable::Displayable(const std::string &name) : displayCode(' '),
                                                    name(name),
                                                    //id("-1/-1"),
                                                    isVisible(-1),
                                                    posX(-1),
                                                    posY(-1)

{
}

const std::string &Displayable::getName() const
{
    return name;
}

/**
void Displayable::setId(int room, int serial)
{
    id = std::to_string(room) + "/" + std::to_string(serial);
}

const std::string &Displayable::getId() const
{
    return id;
}
*/
void Displayable::setVisibility(int isVisible)
{
    this->isVisible = isVisible;
}

bool Displayable::getVisibility() const
{
    return isVisible;
}

void Displayable::setPosX(int x)
{
    posX = x;
}

int Displayable::getPosX() const
{
    return posX;
}

void Displayable::setPosY(int y)
{
    posY = y;
}

int Displayable::getPosY() const
{
    return posY;
}

const GridObject Displayable::getDisplayCode() const
{
    return displayCode;
}

/**
void Displayable::setDisplayGrid(std::shared_ptr<ObjectDisplayGrid> grid)
{
    this->grid = grid;
}

void Displayable::initializeDisplay()
{
    grid->addObjectToDisplay(posX, posY, displayCode);
}
*/

const std::string Displayable::toString() const
{
    std::string str = "   name: " + name + "\n";
    //str += "   id: " + id + "\n";
    str += "   isVisible: " + std::to_string(isVisible) + "\n";
    str += "   posX: " + std::to_string(posX) + "\n";
    str += "   posY: " + std::to_string(posY) + "\n";

    return str;
}