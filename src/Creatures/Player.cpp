#include "Player.hpp"

void Player::setHpMoves(int hpMoves) 
{
    this->hpMoves = hpMoves; 
}

const std::string &Player::toString() const
{
    std::string str = Creature::toString();

    str += "   hpMoves: " + std::to_string(hpMoves) + "\n";

    //std::cout << str << std::endl;
    return str;
}

