#include "BlessCurseOwner.hpp"

BlessCurseOwner::BlessCurseOwner() : Action()
{
}

void BlessCurseOwner::execute()
{
    std::shared_ptr<Item> temp = std::dynamic_pointer_cast<Item>(owner);

    if (temp != nullptr)
    {
        std::shared_ptr<Item> itemToCurse = nullptr;
        std::shared_ptr<Player> player = temp->getOwner();
        if (player != nullptr)
        {
            if (charValue == 'w')
            {
                std::shared_ptr<Item> itemToCurse = player->getSwordWeilded();
                if (itemToCurse != nullptr)
                {
                    owner->printMessage(itemToCurse->getName() + " cursed! " + std::to_string(intValue) + 
                    " taken from its effectiveness.");
                    int itemIntValue = itemToCurse->getIntValue() + intValue;
                    itemToCurse->setItemIntValue(itemIntValue);
                    std::string newName = "+" + std::to_string(itemIntValue) + " Sword";
                    itemToCurse->setName(newName);
                    
                }
                else
                {
                    owner->printMessage("No sword to curse.");
                }
            }
            else if (charValue == 'a')
            {
                std::shared_ptr<Item> itemToCurse = player->getArmorWorn();
                if (itemToCurse != nullptr)
                {
                    owner->printMessage(itemToCurse->getName() + " cursed! " + std::to_string(intValue) + 
                    " taken from its effectiveness.");
                    int itemIntValue = itemToCurse->getIntValue() + intValue;
                    itemToCurse->setItemIntValue(itemIntValue);
                    std::string newName = "+" + std::to_string(itemIntValue) + " Armor";
                    itemToCurse->setName(newName);

                    //owner->printMessage(std::to_string(itemToCurse->getIntValue()));
                }
                else
                {
                    owner->printMessage("No armor to curse.");
                }
            }
        }
    }
}
