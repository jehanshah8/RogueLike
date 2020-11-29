#include "YouWin.hpp"

YouWin::YouWin() : Action()
{
}

void YouWin::execute()
{
    owner->printMessage(message);
    std::shared_ptr<Player> temp = std::dynamic_pointer_cast<Player>(owner);
    if (temp != nullptr)
    {
        int score = temp->getScore() + intValue;
        temp->setScore(score);
    }
}
