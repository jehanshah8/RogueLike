#include "Passage.hpp"

Passage::Passage(int room1, int room2) : Structure(std::to_string(room1) + "/" + std::to_string(room2)),
                                         room1(room1),
                                         room2(room2)
{
    displayCode.setDisplayCode('#');
    supplementaryDisplayCode.setDisplayCode('+');
}
