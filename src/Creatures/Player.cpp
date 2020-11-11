#include "Player.hpp"
#include "../ObjectDisplayGrid.hpp"

Player::Player(const std::string &name, int room, int serial) : Creature(name, '@', room, serial),
                                                                Observer(),
                                                                hpMoves(-1)
{
    //std::cout << "creating player" << std::endl;
}

void Player::setHpMoves(int hpMoves)
{
    this->hpMoves = hpMoves;
}

void Player::addItem(const std::shared_ptr<Item> item)
{
    items.push_back(item);
    item->setPosX(posX);
    item->setPosY(posY);
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
    grid->setTopMessage(hp, 0);
    grid->setBottomMessagePack();
    Creature::initializeDisplay();
}

void Player::move(int dx, int dy)
{
    std::shared_ptr<Displayable> temp = grid->getDisplayable(posX + dx, posY + dy);

    // Is traversable?
    if (temp != nullptr && temp->getDisplayCode() != 'X')
    {
        grid->removeObjectFromDisplay(posX, posY);
        posX += dx;
        posY += dy;
        Creature::initializeDisplay();
    }
}

void Player::showPackContents()
{
    std::string str;
    if (items.empty())
    {
        str += "No items here";
    }
    else
    {
        for (long unsigned int i = 0; i < items.size(); i++)
        {
            str += std::to_string(i) + ": " + items[i]->getName() + ", ";
        }
        str.pop_back();
        str.pop_back();
    }
    grid->setBottomMessagePack(str);
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
    Creature::initializeDisplay();
}

void Player::dropItem(char itemNum)
{
    long unsigned int i = itemNum - '0';
    if (i < items.size())
    {
        items[i]->setPosX(posX);
        items[i]->setPosY(posY);
        items[i]->setOwner(nullptr);

        grid->removeObjectFromDisplay(posX, posY);
        items[i]->initializeDisplay();
        items.erase(items.begin() + i);
        Creature::initializeDisplay();
    }
}

void Player::update(char input)
{
    //std::string str;
    //str += input;
    //grid->setBottomMessageInfo(str);
    //grid->update();
    //grid->setBottomMessagePack();
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
    //case 'c':
    //    // Change, or take off armor ‘c’: armor that is being worn is taken off
    //    // and placed in the pack. If not armor is being worn
    //    // a message should be shown in the info area of the game display.
    //    setArmor();
    //    break;
    case 'd':
        // Drop ‘d’ <integer>: drop item <integer> from the pack.
        // If the <integer> does not refer to an item in the pack and
        // informational message is printed on the game display in the info area.

        if (commandHistory.size() == 2)
        {
            commandHistory.pop();
            dropItem(commandHistory.front());
            commandHistory.pop();
        }
        break;
    //case 'r':
    //    // Read an item ‘r’ <integer>: the item specified by the integer
    //    // must be a scroll that is in the pack. It causes the scroll to perform its actions.
    //    player->readScroll(getchar());
    //    break;
    case 'p':
        // Pick up an item from the dungeon floor ‘p’: pick up the visible item
        // on the dungeon floor location thatthe player is standing on.
        // If multiple items are in the location, only the top item is picked up.
        pickUpItem();
        commandHistory.pop();
        break;
    //case 'T':
    //    // Take out a weapon ‘T’ <integer>: take the sword identified by <integer> from the pack.
    //    // If the identified item is not a sword, or no such item exists,
    //    // show a message in the info area of the game display.
    //    player->weildSword(getchar());
    //    break;
    //case 'w':
    //    // Wear item ‘w’ <integer>: take the armor identified by <integer> from the pack
    //    // and make it the armor being worn. If the identified item is not armor,
    //    // or no such item exists, show a message in the info area of the game display.
    //    player->wearArmor(getchar());
    //    break;
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