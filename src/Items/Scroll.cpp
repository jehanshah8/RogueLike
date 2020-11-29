#include "Scroll.hpp"
#include "../Actions/Action.hpp"
//#include "../ObjectDisplayGrid.hpp"

Scroll::Scroll(const std::string &name, int room, int serial) : Item(name, '?', room, serial)
{
    //std::cout << "creating scroll" << std::endl;
}

void Scroll::activate()
{
    for (auto &it : actions)
    {
        it->execute();
    }

    releaseAllActions();
}