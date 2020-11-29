#include "Teleport.hpp"

Teleport::Teleport() : Action()
{
}

void Teleport::execute()
{
    std::shared_ptr<ObjectDisplayGrid> grid = owner->getObjectDisplayGrid();
    int width = grid->getGameWidth();
    int height = grid->getGameHeight();

    std::shared_ptr<Displayable> temp = nullptr;
    std::shared_ptr<Creature> tempCreature = nullptr;

    while (true)
    {
        int posX = rand() % width;
        int posY = rand() % height;
        temp = grid->getDisplayable(posX, posY);
        tempCreature = std::dynamic_pointer_cast<Creature>(temp);

        // is legal ?
        if (temp != nullptr && temp->getDisplayCode() != 'X')
        {
            // if creature there
            if (tempCreature != nullptr && tempCreature->getIsAlive())
            {
                continue;
            }
            else
            {
                owner->leaveGrid();
                owner->setPosX(posX);
                owner->setPosY(posY);
                grid->addObjectToDisplay(posX, posY, owner);
                grid->update();
                owner->printMessage(message);
                //while(true);
                //grid->update();
                break;
            }
        }
    }
}
