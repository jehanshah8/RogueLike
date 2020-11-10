#include "Passage.hpp"
#include "../ObjectDisplayGrid.hpp"

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

void Passage::setPosY(int y)
{
    path.back()[1] = y;
}

int Passage::getPosX() const { return path.front()[0]; }

int Passage::getPosY() const { return path.front()[1]; }

const std::vector<std::array<int, 2>> Passage::getPath() const
{
    return path; 
}

void Passage::shiftPosY(int shift) 
{
    for (auto &it : path)
    {
        it[1] += shift; 
    }
}

void Passage::initializeDisplay() const
{
    for (unsigned int i = 1; i < path.size(); i++)
    {
        if (path[i - 1][1] == path[i][1])
        {
            if (path[i][0] > path[i - 1][0])
            {
                for (int j = 0; j < path[i][0] - path[i - 1][0]; j++)
                {
                    grid->addObjectToDisplay(path[i - 1][0] + j, path[i - 1][1], floor);
                }
            }
            else
            {
                for (int j = 0; j < path[i - 1][0] - path[i][0]; j++)
                {
                    grid->addObjectToDisplay(path[i - 1][0] - j, path[i - 1][1], floor);
                }
            }
        }
        else
        {
            if (path[i][1] > path[i - 1][1])
            {
                for (int k = 0; k < path[i][1] - path[i - 1][1]; k++)
                {
                    grid->addObjectToDisplay(path[i - 1][0], path[i - 1][1] + k, floor);
                }
            }
            else
            {
                for (int k = 0; k < path[i - 1][1] - path[i][1]; k++)
                {
                    grid->addObjectToDisplay(path[i - 1][0], path[i - 1][1] - k, floor);
                }
            }
        }
    }
    grid->addObjectToDisplay(path.front()[0], path.front()[1], other);
    grid->addObjectToDisplay(path.back()[0], path.back()[1], other);
    Structure::initializeDisplay();
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