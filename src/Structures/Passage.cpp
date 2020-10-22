#include "Passage.hpp"

Passage::Passage(const int room1, const int room2) : Structure(std::to_string(room1) + "/" + std::to_string(room2)),
                                                     room1(room1),
                                                     room2(room2)
{
}
