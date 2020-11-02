#include "Player.hpp"

Player::Player(const std::string &name, int room, int serial) : Creature(name, '@',room, serial),
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
