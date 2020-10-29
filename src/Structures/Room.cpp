#include "Room.hpp"

Room::Room(const std::string &name) : Structure(name)
{
    displayCode.setDisplayCode('.');
    supplementaryDisplayCode.setDisplayCode('X');
}

int Room::getHeight() const
{
    return height;
}

void Room::setHeight(int height)
{
    this->height = height;
}

int Room::getWidth() const
{
    return width;
}

void Room::setWidth(int width)
{
    this->width = width;
}

/**
void Room::initializeDisplay()
{
    for (int row = posY; row < posY + height; row++)
    {
        if (row == posY || row == posY + height - 1)
        {
            for (int col = posX; col < posX + width; col++)
            {
                grid->addObjectToDisplay(row, col, supplementaryDisplayCode);
            }
        }
        else
        {
            grid->addObjectToDisplay(row, posX, supplementaryDisplayCode);
            grid->addObjectToDisplay(row, posX + width - 1, supplementaryDisplayCode);
        }
    }
}
*/

const std::string Room::toString() const
{
    std::string str = Structure::toString();
    str += "   height: " + std::to_string(height) + "\n";
    str += "   width: " + std::to_string(width) + "\n";
    return str;
}