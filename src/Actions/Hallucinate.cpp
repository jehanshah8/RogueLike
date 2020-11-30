#include "Hallucinate.hpp"

Hallucinate::Hallucinate() : Action()
{
}

void Hallucinate::execute()
{

    std::shared_ptr<Item> item = std::dynamic_pointer_cast<Item>(owner);
    std::shared_ptr<Player> player = item->getOwner();
    keyboardListener = player->getKeyboardListener();
    keyboardListener->registerObserver(Observer::downcasted_shared_from_this<Hallucinate>());

    grid = owner->getObjectDisplayGrid();

    owner->printMessage(message);
    //updateGrid();
    //intValue--;
}

void Hallucinate::update(char input)
{
    if (intValue <= 0)
    {
        keyboardListener->removeObserver(Observer::downcasted_shared_from_this<Hallucinate>());

        int x = 0;
        int y = 0;
        for (auto &it1 : grid->objectGrid)
        {
            for (auto &it2 : it1)
            {
                if (!it2.empty())
                {
                    mvaddch(y, x, grid->objectGrid[x][y].top()->getDisplayCode());
                }
                y++;
            }
            x++;
            y = 0;
        }
        grid->update();
        return;
    }

    
    commandHistory.push(input);

    switch (commandHistory.front())
    {
    case 'h':
        // Move left
        updateGrid();
        intValue--;
        commandHistory.pop();
        break;
    case 'l':
        // Move rght
        updateGrid();
        intValue--;
        commandHistory.pop();
        break;
    case 'k':
        // Move up
        updateGrid();
        intValue--;
        commandHistory.pop();
        break;
    case 'j':
        // Move down
        updateGrid();
        intValue--;
        commandHistory.pop();
        break;
    default:
        commandHistory.pop();
    }
}

void Hallucinate::updateGrid()
{
    char displayChars[] = {'.', 'X', '#', '+', ')', ']', '?', '@', 'T', 'S', 'H'};

    int x = 0;
    int y = 0;
    for (auto &it1 : grid->objectGrid)
    {
        for (auto &it2 : it1)
        {
            if (!it2.empty())
            {
                int i = rand() % (sizeof(displayChars) / sizeof(displayChars[0]));
                mvaddch(y, x, displayChars[i]);
            }
            y++;
        }
        x++;
        y = 0;
    }
    grid->update();
}
