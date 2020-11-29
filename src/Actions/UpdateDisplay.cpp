#include "UpdateDisplay.hpp"

UpdateDisplay::UpdateDisplay() : Action()
{
}

void UpdateDisplay::execute()
{
    std::shared_ptr<Creature> temp = std::dynamic_pointer_cast<Creature>(owner);
    if (temp != nullptr)
    {
        temp->updateGrid();
    }
}
