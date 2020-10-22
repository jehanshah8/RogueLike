#include "Displayable.hpp"

Displayable::Displayable(const std::string &name) : name(name),
                                                    id("-1/-1"),
                                                    isVisible(-1),
                                                    posX(-1),
                                                    posY(-1)
                                                    
{
}

std::string Displayable::getName() const
{
    return name;
}

void Displayable::setId(const int room, const int serial)
{
    id = std::to_string(room) + "/" + std::to_string(serial);
}

std::string Displayable::getId() const
{
    return id;
}

void Displayable::setVisibility(const int isVisible)
{
    this->isVisible = isVisible;
}

bool Displayable::getVisibility() const
{
    return isVisible;
}

void Displayable::setPosX(const int x)
{
    posX = x;
}

int Displayable::getPosX() const
{
    return posX;
}

void Displayable::setPosY(const int y)
{
    posY = y;
}

int Displayable::getPosY() const
{
    return posY;
}

std::string Displayable::toString() const
{
    return name + "\n" +
           id + "\n" +
           std::to_string(isVisible) + "\n" +
           std::to_string(posX) + "\n" +
           std::to_string(posY) + "\n";
}