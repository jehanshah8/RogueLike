#include "Remove.hpp"

Remove::Remove() : Action()
{
}

void Remove::execute()
{
    owner->leaveGrid();
}