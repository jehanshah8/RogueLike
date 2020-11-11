#include "Dungeon.hpp"

Dungeon::Dungeon(const std::string &name, int gameWidth, int topHeight, int gameHeight, int bottomHeight) : Observer(),
                                                                                                            name(name),
                                                                                                            gameHeight(gameHeight),
                                                                                                            gameWidth(gameWidth),
                                                                                                            topHeight(topHeight),
                                                                                                            bottomHeight(bottomHeight)

{
    grid = std::make_shared<ObjectDisplayGrid>(gameHeight, gameWidth, topHeight, bottomHeight);
    keyboardListener = std::make_shared<KeyboardListener>();
}

int Dungeon::getGameHeight() const { return gameHeight; }
int Dungeon::getGameWidth() const { return gameWidth; }
int Dungeon::getTopHeight() const { return topHeight; }
int Dungeon::getBottomHeight() const { return bottomHeight; }

const std::vector<std::shared_ptr<Room>> Dungeon::getRooms() const
{
    return rooms;
}

void Dungeon::addRoom(const std::shared_ptr<Room> room)
{
    rooms.push_back(room);
}

const std::vector<std::shared_ptr<Passage>> Dungeon::getPassages() const
{
    return passages;
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

void Dungeon::initializeGrid()
{
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
    grid->setBottomMessageInfo("Welcome");
    grid->update();
}

void Dungeon::startGame()
{
    // Initialize the gird
    initializeGrid();
    
    keyboardListener->registerObserver(shared_from_this());
    std::thread keyboardListenerThread (&KeyboardListener::run, keyboardListener);

    keyboardListenerThread.join();
}

void Dungeon::endGame()
{
    grid->setBottomMessageInfo("Game Over!");
    grid->update();

    keyboardListener->kill();

    grid->removeAll();
}

void Dungeon::update(char input)
{
    
    std::string str;
    str += input;
    grid->setBottomMessageInfo(str);
    grid->update();
    //keyboardListener->kill();
    switch (input)
    {
    case '?':
        // Help: ‘?’: show the different commands in the info section of the display
        //etHelp();
        break;
    case 'H':
        // Help ‘H’ <command>give more detailed information about the specified
        //command in the info section ofthe display.
        //getHelp(std::tolower(getchar()));
        break;
    case 'E':
        //bool confirm = std::tolower(getchar()) == 'y';
        //if (confirm)
        //{
        //    endGame();
        //}
        
        endGame();
        break;
    }
}