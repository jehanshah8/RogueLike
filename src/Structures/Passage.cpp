#include "Passage.hpp"

Passage::Passage(int room1, int room2) : Structure("passage" + std::to_string(room1) + "--" + std::to_string(room2)),
                                         room1(room1),
                                         room2(room2)
{
    //std::cout << "creating passage" << std::endl;
    displayCode.setDisplayCode('#');
    supplementaryDisplayCode.setDisplayCode('+');
}

const std::string Passage::toString() const
{
    std::string str = Structure::toString();
    str += "\n\t\tplayer in the passage: \n";
    str += toStringPlayer();
    str += "\n\t\tmonsters in the passage: \n";
    str += toStringMonsters();
    str += "\n\t\titems in the passage: \n";
    str += toStringItems();

    return str;
}