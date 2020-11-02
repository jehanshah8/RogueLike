#include "Dungeon.hpp"

Dungeon::Dungeon(const std::string &name, int gameWidth, int topHeight, int gameHeight, int bottomHeight) : name(name),
                                                                                                            gameHeight(gameHeight),
                                                                                                            gameWidth(gameWidth),
                                                                                                            topHeight(topHeight),
                                                                                                            bottomHeight(bottomHeight)
{
    grid = std::make_shared<ObjectDisplayGrid>(gameHeight, gameWidth, topHeight, bottomHeight);
}

int Dungeon::getGameHeight() const { return gameHeight; }
int Dungeon::getGameWidth() const { return gameWidth; }
int Dungeon::getTopHeight() const { return topHeight; }
int Dungeon::getBottomHeight() const { return bottomHeight; }

void Dungeon::addRoom(const std::shared_ptr<Room> room)
{
    rooms.push_back(room);
}

void Dungeon::addPassage(const std::shared_ptr<Passage> passage)
{
    passages.push_back(passage);
}

void Dungeon::addMonster(const std::shared_ptr<Monster> monster)
{
    monsters.push_back(monster);
}

void Dungeon::addPlayer(const std::shared_ptr<Player> player)
{
    this->player = player;
}

std::shared_ptr<Player> Dungeon::getPlayer() const
{
    return player;
}

void Dungeon::addItem(const std::shared_ptr<Item> item)
{
    items.push_back(item);
}

void Dungeon::initializeGrid()
{
    //player->setObjectDisplayGrid(grid);
    //player->initializeDisplay();

    for (auto &it : rooms)
    {
        it->setObjectDisplayGrid(grid);
        it->initializeDisplay();
    }
    
    for (auto &it : passages)
    {
        it->setObjectDisplayGrid(grid);
        it->initializeDisplay();
    }
    runDisplay();
    //std::thread displayThread(Dungeon::runDisplay);
    //displayThread.join();
}

const std::string Dungeon::toString() const
{
    std::string str = "\tDungeon: \n";
    str += "\tname: " + name + "\n";
    str += "\tgameHeight: " + std::to_string(gameHeight) + "\n";
    str += "\tgameWidth: " + std::to_string(gameWidth) + "\n";
    str += "\ttopHeight: " + std::to_string(topHeight) + "\n";
    str += "\tbottomHeight: " + std::to_string(bottomHeight) + "\n";

    str += "\trooms in the dungeon: \n";
    for (auto &it : rooms)
    {
        str += it->toString() + "\n";
    }

    str += "\tpassages in the dungeon: \n";
    for (auto &it : passages)
    {
        str += it->toString() + "\n";
    }

    return str;
}

std::atomic_bool Dungeon::isRunning(true);

void Dungeon::runDisplay()
{

    // loop over each step, doubling each time
    // stop loop if isRunning is swapped to false
    while (isRunning)
    {
        // update the grid
        grid->update();

        // wait a bit to rejoin
        // wait in a few steps to update faster on keypress
        for (int i = 0; (isRunning && i < 5); i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
        }
    }
}