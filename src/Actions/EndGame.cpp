#include "EndGame.hpp"

EndGame::EndGame() : Action()
{
}

void EndGame::execute()
{
   owner->printMessage(message);
}
