#include "Hallucinate.hpp"

Hallucinate::Hallucinate() : Action()
{
}

void Hallucinate::execute()
{
    owner->printMessage("hallucinating");
}
