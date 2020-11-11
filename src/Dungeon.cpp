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

    commandInfo['h'] = "Move left 1 space.";
    commandInfo['l'] = "Move right 1 space.";
    commandInfo['k'] = "Move up 1 space.";
    commandInfo['j'] = "Move down 1 space.";
    commandInfo['i'] = "Inventory--show pack contents.";
    commandInfo['c'] = "Take off/change armor.";
    commandInfo['d'] = "Drop <item number> item from pack.";
    commandInfo['d'] = "Drop <item number> item from pack.";
    commandInfo['p'] = "Pick up item under player and put into the pack.";
    commandInfo['r'] = "Read the scroll which is item number <item number> in pack.";
    commandInfo['t'] = "Take out <item number> weapon from pack";
    commandInfo['w'] = "Wear <item number> armor from pack.";
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
    grid->setBottomMessageInfo("Game On!");
    grid->update();
}

void Dungeon::getAllCommands()
{
    std::string str;
    for (auto &it : commandInfo)
    {
        str += it.first;
        str += ", ";
    }
    str.pop_back();
    str.pop_back();

    grid->setBottomMessageInfo(str);
    grid->update();
}

void Dungeon::getHelpOnCommand(char command)
{
    std::string str;
    std::unordered_map<char, std::string>::const_iterator it = commandInfo.find(command);

    if (it == commandInfo.end())
    {
        str = "No command '";
        str += command;
        str += "'. Press '?' to see a list of all commands";
    }
    else
    {
        str = it->second;
    }

    grid->setBottomMessageInfo(str);
    grid->update();
}

void Dungeon::endGame()
{
    grid->setBottomMessageInfo("Game Over!");
    grid->update();

    keyboardListener->kill();
    grid->removeAllObjects();
}

void Dungeon::update(char input)
{
    std::string str;
    str += input;
    grid->setBottomMessageInfo(str);
    grid->update();

    commandHistory.push(input);

    switch (commandHistory.front())
    {
    case '?':
        // Help: ‘?’: show the different commands in the info section of the display
        getAllCommands();
        commandHistory.pop();
        break;
    case 'H':
        // Help ‘H’ <command>give more detailed information about the specified
        //command in the info section ofthe display.
        if (commandHistory.size() == 2)
        {
            commandHistory.pop();
            getHelpOnCommand(commandHistory.front());
            commandHistory.pop();
        }
        break;
    case 'E':
        if (commandHistory.size() == 2)
        {
            commandHistory.pop();
            if (commandHistory.front() == 'y' || commandHistory.front() == 'Y')
            {
                endGame();
            }
            commandHistory.pop();
        }
        else
        {
            grid->setBottomMessageInfo("Press 'Y' or 'y' to confirm.");
            grid->update();
        }
        break;
    default:
        commandHistory.pop();
    }
}

void Dungeon::startGame()
{
    // Initialize the gird
    initializeGrid();

    keyboardListener->registerObserver(Observer::downcasted_shared_from_this<Dungeon>());
    player->run(keyboardListener);
    std::thread keyboardListenerThread(&KeyboardListener::run, keyboardListener);

    keyboardListenerThread.join();
}