#include "DropPack.hpp"

DropPack::DropPack() : Action()
{
}

void DropPack::execute()
{
    std::shared_ptr<Player> temp = std::dynamic_pointer_cast<Player>(owner);
    if (temp != nullptr)
    {
        owner->printMessage(message);
        temp->dropItem('1');
    }
}
