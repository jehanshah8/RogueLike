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

void Player::update(char input)
{
    //std::string str;
    //str += input;
    //grid->setBottomMessageInfo(str);
    //grid->update();

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