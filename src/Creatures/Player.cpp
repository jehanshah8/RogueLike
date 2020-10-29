#include "Player.hpp"

Player::Player(const std::string &name, int room, int serial) : Creature(name, room, serial),
                                                                hpMoves(-1)
{
    //std::cout << "creating player" << std::endl;
}

void Player::setHpMoves(int hpMoves)
{
    this->hpMoves = hpMoves;
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
