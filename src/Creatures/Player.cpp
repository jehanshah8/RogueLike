#include "Player.hpp"
#include "../ObjectDisplayGrid.hpp"
#include "../Actions/Action.hpp"
#include "../Dungeon.hpp"

Player::Player(const std::string &name, int room, int serial) : Creature(name, '@', room, serial),
                                                                Observer(),
                                                                hpMoves(-1),
                                                                isWeildingSword(false),
                                                                swordBonus(0),
                                                                isWearingArmor(false),
                                                                armorBonus(0),
                                                                moveCount(0),
                                                                score(0)
{
    //std::cout << "creating player" << std::endl;
}

void Player::setHpMoves(int hpMoves)
{
    this->hpMoves = hpMoves;
}

void Player::setScore(int score)
{
    this->score = score;
}

const int Player::getScore() const
{
    return score;
}

void Player::addItem(const std::shared_ptr<Item> item)
{
    items.push_back(item);
    item->setPosX(posX);
    item->setPosY(posY);
    item->setOwner(Displayable::downcasted_shared_from_this<Player>());
}

const std::string Player::toStringItems() const
{
    std::string str;
    if (items.empty())
    {
        str += "\t\t\t\tno items here\n";
    }
    else
    {
        for (auto &it : items)
        {
            str += it->toString(4) + "\n";
        }
    }

    return str;
}

const std::string Player::toString() const
{
    std::string str = Creature::toString();

    str += "\t\t\thpMoves: " + std::to_string(hpMoves) + "\n";

    str += "\n\t\t\tplayer items: \n";
    str += toStringItems();

    //std::cout << str << std::endl;
    return str;
}

void Player::initializeDisplay()
{
    for (auto &it : items)
    {
        it->setObjectDisplayGrid(grid);
    }

    grid->setTopMessage(hp, score);
    grid->setBottomMessage1("Pack: ");
    Creature::initializeDisplay();
}

void Player::getHit(const std::shared_ptr<Creature> attacker, int damage)
{
    damage -= armorBonus;
    if (damage > 0)
    {
        hp -= damage;
    }
    std::string str = "Info: Got hit. Damage: " + std::to_string(damage);
    grid->setBottomMessage2(str);
    grid->update();

    //
    //grid->setBottomMessage1(std::to_string(deathActions.size()));
    //grid->update();
    //

    if (hp < 0)
    {
        isAlive = false;
        for (auto &it : deathActions)
        {
            it->execute();
        }
        endGame();
    }
    else
    {
        for (auto &it : hitActions)
        {
            it->execute();
        }
    }
}

void Player::move(int dx, int dy)
{
    std::shared_ptr<Displayable> temp = grid->getDisplayable(posX + dx, posY + dy);
    std::shared_ptr<Creature> tempCreature = std::dynamic_pointer_cast<Creature>(temp);
    // Is traversable?
    if (temp != nullptr && temp->getDisplayCode() != 'X')
    {
        if (tempCreature != nullptr && tempCreature->getIsAlive())
        {
            int damage = (rand() % (maxHit + 1)) + swordBonus;
            tempCreature->getHit(Displayable::downcasted_shared_from_this<Player>(), damage);
            grid->setTopMessage(hp, 0);
            grid->update();
        }
        else
        {
            grid->removeObjectFromDisplay(posX, posY);
            posX += dx;
            posY += dy;
            Creature::initializeDisplay();
            moveCount++;
            if (moveCount % hpMoves == 0)
            {
                hp++;
                grid->setTopMessage(hp, 0);
                grid->update();
            }
        }
    }
    else
    {
        grid->setBottomMessage2("Info: Cannot move there!");
        grid->update();
    }
}

void Player::showPackContents()
{
    std::string str = "Pack: ";
    if (items.empty())
    {
        str += "No items here";
    }
    else
    {
        for (long unsigned int i = 0; i < items.size(); i++)
        {
            str += std::to_string(i + 1) + ": " + items[i]->getName() + items[i]->getIsEquippedStr() + ", ";
        }
        str.pop_back();
        str.pop_back();
    }
    grid->setBottomMessage1(str);
    grid->update();
}

void Player::pickUpItem()
{
    grid->removeObjectFromDisplay(posX, posY);
    std::shared_ptr<Item> temp = std::dynamic_pointer_cast<Item>(grid->getDisplayable(posX, posY));

    // Something there?
    if (temp != nullptr)
    {
        temp->setOwner(Displayable::downcasted_shared_from_this<Player>());
        items.push_back(temp);
        grid->removeObjectFromDisplay(posX, posY);
    }
    else
    {
        grid->setBottomMessage2("Info: Nothing item here.");
        grid->update();
    }
    Creature::initializeDisplay();
}

void Player::dropItem(char itemNum)
{
    long unsigned int i = itemNum - '0' - 1;
    if (i < items.size())
    {
        items[i]->setPosX(posX);
        items[i]->setPosY(posY);
        if (items[i]->getIsEquipped())
        {
            std::shared_ptr<Sword> tempSword = std::dynamic_pointer_cast<Sword>(items[i]);
            if (tempSword != nullptr)
            {
                isWeildingSword = false;
                swordBonus = 0;
            }
            else
            {
                isWearingArmor = false;
                armorBonus = 0;
            }
        }
        items[i]->unequip();
        items[i]->releaseAllActions();
        items[i]->setOwner(nullptr);
        grid->removeObjectFromDisplay(posX, posY);
        items[i]->initializeDisplay();
        items.erase(items.begin() + i);
        Creature::initializeDisplay();
    }
    else
    {
        grid->setBottomMessage2("Info: Invalid item number.");
        grid->update();
    }
}

void Player::weildSword(char itemNum)
{
    if (isWeildingSword)
    {
        grid->setBottomMessage2("Info: Already weilding a sword.");
        grid->update();
        return;
    }
    long unsigned int i = itemNum - '0' - 1;
    std::shared_ptr<Sword> temp = std::dynamic_pointer_cast<Sword>(items[i]);

    if (i < items.size() && temp != nullptr)
    {
        isWeildingSword = true;
        swordBonus = temp->getIntValue();
        temp->equip();
    }
    else
    {
        grid->setBottomMessage2("Info: Item selected is not a sword.");
        grid->update();
    }
}

void Player::wearArmor(char itemNum)
{
    if (isWearingArmor)
    {
        grid->setBottomMessage2("Info: Already wearing an armor.");
        grid->update();
        return;
    }
    long unsigned int i = itemNum - '0' - 1;
    std::shared_ptr<Armor> temp = std::dynamic_pointer_cast<Armor>(items[i]);

    if (i < items.size() && temp != nullptr)
    {
        isWearingArmor = true;
        armorBonus = temp->getIntValue();
        temp->equip();
    }
    else
    {
        grid->setBottomMessage2("Info: Item selected is not an armor.");
        grid->update();
    }
}

void Player::takeOffArmor()
{
    if (isWearingArmor)
    {
        for (long unsigned int i = 0; i < items.size(); i++)
        {
            std::shared_ptr<Armor> temp = std::dynamic_pointer_cast<Armor>(items[i]);

            if (temp != nullptr && temp->getIsEquipped())
            {
                isWearingArmor = false;
                armorBonus = 0;
                temp->unequip();
                break;
            }
        }
    }
    else
    {
        grid->setBottomMessage2("Info: No armor worn.");
        grid->update();
    }
}

void Player::readScroll(char itemNum)
{
    long unsigned int i = itemNum - '0' - 1;
    std::shared_ptr<Scroll> temp = std::dynamic_pointer_cast<Scroll>(items[i]);

    if (i < items.size() && temp != nullptr)
    {
        temp->activate();
        items.erase(items.begin() + i);
    }
    else
    {
        grid->setBottomMessage2("Info: Item selected is not a scroll.");
        grid->update();
    }
}

void Player::releaseAllItems()
{
    for (auto &it : items)
    {
        it->releaseAllActions();
        it->setOwner(nullptr);
    }
}

void Player::setDungeon(const std::shared_ptr<Dungeon> dungeon)
{
    this->dungeon = dungeon;
}

void Player::endGame()
{
    dungeon->endGame();
    //keyboardListener->kill();
    //grid->removeAllObjects();
    //releaseAllItems();
    //Creature::releaseAllActions();
}

void Player::update(char input)
{
    grid->setBottomMessage2("Info: ");
    grid->update();
    commandHistory.push(input);

    switch (commandHistory.front())
    {
    case 'h':
        // Move left
        move(-1, 0);
        commandHistory.pop();
        break;
    case 'l':
        // Move rght
        move(1, 0);
        commandHistory.pop();
        break;
    case 'k':
        // Move up
        move(0, 1);
        commandHistory.pop();
        break;
    case 'j':
        // Move down
        move(0, -1);
        commandHistory.pop();
        break;
    case 'i':
        // The ‘I’ (inventory) command should display, at the bottom of the display, the contents of the pack, and
        // an identifying number that can be used to refer to the item when it is dropped.
        showPackContents();
        commandHistory.pop();
        break;
    case 'd':
        // Drop ‘d’ <integer>: drop item <integer> from the pack.
        // If the <integer> does not refer to an item in the pack and
        // informational message is printed on the game display in the info area.
        showPackContents();
        if (commandHistory.size() == 2)
        {
            commandHistory.pop();
            dropItem(commandHistory.front());
            commandHistory.pop();
        }
        showPackContents();
        break;
    case 'r':
        // Read an item ‘r’ <integer>: the item specified by the integer
        // must be a scroll that is in the pack. It causes the scroll to perform its actions.
        showPackContents();
        if (commandHistory.size() == 2)
        {
            commandHistory.pop();
            readScroll(commandHistory.front());
            commandHistory.pop();
        }
        //showPackContents();
        break;
    case 'p':
        // Pick up an item from the dungeon floor ‘p’: pick up the visible item
        // on the dungeon floor location thatthe player is standing on.
        // If multiple items are in the location, only the top item is picked up.
        pickUpItem();
        commandHistory.pop();
        showPackContents();
        break;
    case 'T':
        // Take out a weapon ‘T’ <integer>: take the sword identified by <integer> from the pack.
        // If the identified item is not a sword, or no such item exists,
        // show a message in the info area of the game display.
        showPackContents();
        if (commandHistory.size() == 2)
        {
            commandHistory.pop();
            weildSword(commandHistory.front());
            commandHistory.pop();
        }
        showPackContents();
        break;
    case 'w':
        // Wear item ‘w’ <integer>: take the armor identified by <integer> from the pack
        // and make it the armor being worn. If the identified item is not armor,
        // or no such item exists, show a message in the info area of the game display.
        showPackContents();
        if (commandHistory.size() == 2)
        {
            commandHistory.pop();
            wearArmor(commandHistory.front());
            commandHistory.pop();
        }
        showPackContents();
        break;
    case 'c':
        // Change, or take off armor ‘c’: armor that is being worn is taken off
        // and placed in the pack. If not armor is being worn
        // a message should be shown in the info area of the game display.
        takeOffArmor();
        commandHistory.pop();
        showPackContents();
        break;
    case 'H':
        // Help ‘H’ <command>give more detailed information about the specified
        //command in the info section ofthe display.
        if (commandHistory.size() == 2)
        {
            commandHistory.pop();
            commandHistory.pop();
        }
        break;
    case 'E':
        if (commandHistory.size() == 2)
        {
            commandHistory.pop();
            commandHistory.pop();
        }
        break;
    default:
        commandHistory.pop();
    }
}

void Player::run(std::shared_ptr<KeyboardListener> keyboardListener)
{
    this->keyboardListener = keyboardListener;
    keyboardListener->registerObserver(Observer::downcasted_shared_from_this<Player>());
}

const std::shared_ptr<Sword> Player::getSwordWeilded() const
{
    if (!isWeildingSword)
    {
        return nullptr;
    }

    std::shared_ptr<Sword> swordWeilded = nullptr;
    for (auto &it : items)
    {
        swordWeilded = std::dynamic_pointer_cast<Sword>(it);
        if (swordWeilded != nullptr && swordWeilded->getIsEquipped())
        {
            return swordWeilded;
        }
    }
}

const std::shared_ptr<Armor> Player::getArmorWorn() const
{
    if (!isWearingArmor)
    {
        return nullptr;
    }

    std::shared_ptr<Armor> armorWorn = nullptr;
    for (auto &it : items)
    {
        armorWorn = std::dynamic_pointer_cast<Armor>(it);
        if (armorWorn != nullptr && armorWorn->getIsEquipped())
        {
            return armorWorn;
        }
    }
}

const std::shared_ptr<KeyboardListener> Player::getKeyboardListener() const
{
    return keyboardListener;
}