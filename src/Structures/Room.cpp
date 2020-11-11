#include "Room.hpp"
#include "../ObjectDisplayGrid.hpp"

Room::Room(const std::string &name) : Structure("room" + name, '.', 'X')
{
    //std::cout << "creating room" << std::endl;
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

void Room::initializeDisplay() const
{
    for (int x = posX; x < posX + width; x++)
    {
        for (int y = posY; y < posY + height; y++)
        {
            if (x == posX || x == posX + width - 1)
            {
                grid->addObjectToDisplay(x, y, other);
            }
            else if (y == posY || y == posY + height - 1)
            {
                grid->addObjectToDisplay(x, y, other);
            }
            else
            {
                grid->addObjectToDisplay(x, y, floor);
            }
        }
    }
    Structure::initializeDisplay();
}

const std::string Room::toString() const
{
    std::string str = Structure::toString();
    str += "\t\theight: " + std::to_string(height) + "\n";
    str += "\t\twidth: " + std::to_string(width) + "\n";
    str += "\n\t\tplayer in the room: \n";
    str += toStringPlayer();
    str += "\n\t\tmonsters in the room: \n";
    str += toStringMonsters();
    str += "\n\t\titems in the room: \n";
    str += toStringItems();

    return str;
}