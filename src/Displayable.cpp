#include "Displayable.hpp"
#include "ObjectDisplayGrid.hpp"

//std::shared_ptr<ObjectDisplayGrid> Displayable::grid;

Displayable::Displayable(const std::string &name, char displayCode) : displayCode(displayCode),
                                                                      name(name),
                                                                      isVisible(-1),
                                                                      posX(-1),
                                                                      posY(-1)

{
}

const std::string &Displayable::getName() const
{
    return name;
}

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

char Displayable::getDisplayCode() const
{
    return displayCode;
}

void Displayable::setDisplaycode(char displayCode)
{
    this->displayCode = displayCode;
}

const std::string Displayable::toString(int indentation) const
{
    std::string str;
    for (int i = 0; i < indentation; i++)
    {
        str += "\t";
    }
    str += "name: " + name + "\n";
    for (int i = 0; i < indentation; i++)
    {
        str += "\t";
    }
    str += "isVisible: " + std::to_string(isVisible) + "\n";
    for (int i = 0; i < indentation; i++)
    {
        str += "\t";
    }
    str += "posX: " + std::to_string(posX) + "\n";
    for (int i = 0; i < indentation; i++)
    {
        str += "\t";
    }
    str += "posY: " + std::to_string(posY) + "\n";

    return str;
}

void Displayable::setObjectDisplayGrid(const std::shared_ptr<ObjectDisplayGrid> grid)
{
    this->grid = grid;
}

const std::shared_ptr<ObjectDisplayGrid> Displayable::getObjectDisplayGrid() const
{
    return grid;
}

void Displayable::initializeDisplay()
{
    grid->addObjectToDisplay(posX, posY, shared_from_this());
    grid->update();
}

void Displayable::leaveGrid()
{
    grid->removeObjectFromDisplay(posX, posY);
    grid->update();
}
//Displayable::~Displayable()
//{
//    grid->removeObjectFromDisplay(posX, posY);
//}

void Displayable::printMessage(const std::string &msg)
{
    std::string str = "Info: " + msg;
    grid->setBottomMessage2(str);
    grid->update();
}