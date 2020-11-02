#include "Passage.hpp"

Passage::Passage(int room1, int room2) : Structure("passage" + std::to_string(room1) + "--" + std::to_string(room2), '#', '+'),
                                         room1(room1),
                                         room2(room2)
{
    //std::cout << "creating passage" << std::endl;
}

void Passage::setPosX(int x)
{
    path.push_back({x, -1});
}

int Passage::getPosX() const { return -1; }

int Passage::getPosY() const { return -1; }

void Passage::setPosY(int y)
{
    path.back()[1] = y;
}

void Passage::initializeDisplay() const
{
    Structure::initializeDisplay();

    grid->addObjectToDisplay(path[0][0], path[0][1], supplementaryDisplayCode);
}

const std::string Passage::toString() const
{
    //std::string str = Structure::toString();
    int indentation = 2;
    std::string str;
    for (int i = 0; i < indentation; i++)
    {
        str += "\t";
    }
    str += "name: " + name + "\n";
    //str += "   id: " + id + "\n";
    for (int i = 0; i < indentation; i++)
    {
        str += "\t";
    }
    str += "isVisible: " + std::to_string(isVisible) + "\n";

    for (auto &it : path)
    {
        for (int i = 0; i < indentation; i++)
        {
            str += "\t";
        }
        str += "posX, posY: " + std::to_string(it[0]) + ", " + std::to_string(it[1]) + "\n";
    }

    str += "\n\t\tplayer in the passage: \n";
    str += toStringPlayer();
    str += "\n\t\tmonsters in the passage: \n";
    str += toStringMonsters();
    str += "\n\t\titems in the passage: \n";
    str += toStringItems();

    return str;
}