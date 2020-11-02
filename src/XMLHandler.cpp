#include "XMLHandler.hpp"

//helpers
//From https://www.tutorialspoint.com/case-insensitive-string-comparison-in-cplusplus
int case_insensitive_match(std::string s1, std::string s2)
{
    //convert s1 and s2 into lower case strings
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower); //std overloads tolower, ::tolower is the definition in the global namespace
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if (s1.compare(s2) == 0)
        return 1;
    return 0;
}

inline std::string boolToString(bool booleanValue)
{
    return booleanValue ? "true" : "false";
}

std::shared_ptr<Dungeon> XMLHandler::getDungeon()
{
    return dungeonBeingParsed;
}

std::string xmlChToString(const XMLCh *xmlChName, int length = -1)
{
    //Xerces Parses file into XMLCh* string. So use Transcode to allocate a char* buffer
    char *chStarName = xercesc::XMLString::transcode(xmlChName);
    if (length == -1)
    {
        std::string StrName(chStarName);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }
    else
    {
        std::string StrName(chStarName, 0, length);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }
}

const XMLCh *getXMLChAttributeFromString(const xercesc::Attributes &attributes, const char *strGet)
{
    XMLCh *xmlChGet = xercesc::XMLString::transcode(strGet);
    const XMLCh *xmlChAttr = attributes.getValue(xmlChGet);
    xercesc::XMLString::release((&xmlChGet));
    return xmlChAttr;
}

void XMLHandler::startElement(const XMLCh *uri, const XMLCh *localName, const XMLCh *qName, const xercesc::Attributes &attributes)
{

    char *qNameStr = xercesc::XMLString::transcode(qName);
    if (DEBUG > 1)
    {
        std::cout << CLASSID << ".startElement qName: " << qNameStr << std::endl;
    }

    if (case_insensitive_match(qNameStr, "Dungeon"))
    {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int width = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "width")));
        int topHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "topHeight")));
        int gameHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "gameHeight")));
        int bottomHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "bottomHeight")));

        // printing for parsing and debugging only
        //std::string str = "Dungeon: \n";
        //str += "   name: " + name + "\n";
        //str += "   width: " + std::to_string(width) + "\n";
        //str += "   topHeight: " + std::to_string(topHeight) + "\n";
        //str += "   gameHeight: " + std::to_string(gameHeight) + "\n";
        //str += "   bottomHeight: " + std::to_string(bottomHeight) + "\n";
        //std::cout << str << std::endl;
        // end print

        dungeonBeingParsed = std::make_shared<Dungeon>(name, width, topHeight, gameHeight, bottomHeight);
    }
    else if (case_insensitive_match(qNameStr, "Rooms"))
    {
        //std::cout << "Rooms\n" << std::endl;
        ;
    }
    else if (case_insensitive_match(qNameStr, "Room"))
    {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "room"));
        structureBeingParsed = std::make_shared<Room>(name);
        displayablesBeingParsed.push(structureBeingParsed);
    }
    else if (case_insensitive_match(qNameStr, "Passages"))
    {
        //std::cout << "Passages\n" << std::endl;
        ;
    }
    else if (case_insensitive_match(qNameStr, "Passage"))
    {
        int room1 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room1")));
        int room2 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room2")));

        structureBeingParsed = std::make_shared<Passage>(room1, room2);
        displayablesBeingParsed.push(structureBeingParsed);
    }
    else if (case_insensitive_match(qNameStr, "Monster"))
    {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));

        creatureBeingParsed = std::make_shared<Monster>(name, room, serial);
        displayablesBeingParsed.push(creatureBeingParsed);
    }
    else if (case_insensitive_match(qNameStr, "Player"))
    {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));

        creatureBeingParsed = std::make_shared<Player>(name, room, serial);
        displayablesBeingParsed.push(creatureBeingParsed);
    }
    else if (case_insensitive_match(qNameStr, "Scroll"))
    {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));

        itemBeingParsed = std::make_shared<Scroll>(name, room, serial);
        displayablesBeingParsed.push(itemBeingParsed);
    }
    else if (case_insensitive_match(qNameStr, "Armor"))
    {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));

        itemBeingParsed = std::make_shared<Armor>(name, room, serial);
        displayablesBeingParsed.push(itemBeingParsed);
    }
    else if (case_insensitive_match(qNameStr, "Sword"))
    {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
        int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));

        itemBeingParsed = std::make_shared<Sword>(name, room, serial);
        displayablesBeingParsed.push(itemBeingParsed);
    }
    else if (case_insensitive_match(qNameStr, "CreatureAction"))
    {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        std::string type = xmlChToString(getXMLChAttributeFromString(attributes, "type"));
        // todo
        /**
        if (name.compare("Print"))
        {
            actionBeingParsed = std::make_shared<Print> ();
        }
        else if (name.compare("Teleport"))
        {
            actionBeingParsed = std::make_shared<Teleport> ();
        }
        else if (name.compare("YouWin"))
        {
            actionBeingParsed = std::make_shared<YouWin> ();
        }
        else if (name.compare("DropPack"))
        {
            actionBeingParsed = std::make_shared<DropPack> ();
        }
        else if (name.compare("EmptyPack"))
        {
            actionBeingParsed = std::make_shared<EmptyPack> ();
        }

        if (type.compare("death"))
        {
            creatureBeingParsed->addDeathAction(std::dynamic_pointer_cast<CreatureAction>(actionBeingParsed));
        }
        else if (type.compare("hit"))
        {
            creatureBeingParsed->addHitAction(std::dynamic_pointer_cast<CreatureAction>(actionBeingParsed));
        }
        */
        // printing for parsing and debugging only
        //std::string str = "CreatureAction: \n";
        //str += "   name: " + name + "\n";
        //str += "   type: " + type + "\n";
        //std::cout << str << std::endl;
        // end print
    }
    else if (case_insensitive_match(qNameStr, "ItemAction"))
    {
        std::string name = xmlChToString(getXMLChAttributeFromString(attributes, "name"));
        std::string type = xmlChToString(getXMLChAttributeFromString(attributes, "type"));

        // todo
        // printing for parsing and debugging only
        //std::string str = "ItemAction: \n";
        //str += "   name: " + name + "\n";
        //str += "   type: " + type + "\n";
        //std::cout << str << std::endl;
        // end print
    }
    else if (case_insensitive_match(qNameStr, "visible"))
    {
        bVisible = true;
    }
    else if (case_insensitive_match(qNameStr, "posX"))
    {
        bPosX = true;
    }
    else if (case_insensitive_match(qNameStr, "posY"))
    {
        bPosY = true;
    }
    else if (case_insensitive_match(qNameStr, "width"))
    {
        bWidth = true;
    }
    else if (case_insensitive_match(qNameStr, "height"))
    {
        bHeight = true;
    }
    else if (case_insensitive_match(qNameStr, "hp"))
    {
        bHp = true;
    }
    else if (case_insensitive_match(qNameStr, "maxHit"))
    {
        bMaxHit = true;
    }
    else if (case_insensitive_match(qNameStr, "type"))
    {
        bType = true;
    }
    else if (case_insensitive_match(qNameStr, "hpMoves"))
    {
        bHpMoves = true;
    }
    else if (case_insensitive_match(qNameStr, "itemIntValue"))
    {
        bItemIntValue = true;
    }
    else if (case_insensitive_match(qNameStr, "actionMessage"))
    {
        bActionMessage = true;
    }
    else if (case_insensitive_match(qNameStr, "actionIntValue"))
    {
        bActionIntValue = true;
    }
    else if (case_insensitive_match(qNameStr, "actionCharValue"))
    {
        bActionCharValue = true;
    }
    else
    {
        std::cout << "Unknown qname: " << qNameStr << std::endl;
    }
    xercesc::XMLString::release(&qNameStr);
}

void XMLHandler::endElement(const XMLCh *uri, const XMLCh *localName, const XMLCh *qName)
{
    if (bVisible)
    {
        displayablesBeingParsed.top()->setVisibility(std::stoi(data));
        bVisible = false;
    }
    else if (bPosX)
    {
        displayablesBeingParsed.top()->setPosX(std::stoi(data));
        bPosX = false;
    }
    else if (bPosY)
    {
        displayablesBeingParsed.top()->setPosY(std::stoi(data));
        bPosY = false;
    }
    else if (bWidth)
    {
        std::dynamic_pointer_cast<Room>(structureBeingParsed)->setWidth(std::stoi(data));
        bWidth = false;
    }
    else if (bHeight)
    {
        std::dynamic_pointer_cast<Room>(structureBeingParsed)->setHeight(std::stoi(data));
        bHeight = false;
    }
    else if (bHp)
    {
        creatureBeingParsed->setHp(std::stoi(data));
        bHp = false;
    }
    else if (bMaxHit)
    {
        creatureBeingParsed->setMaxHit(std::stoi(data));
        bMaxHit = false;
    }
    else if (bType)
    {
        std::dynamic_pointer_cast<Monster>(creatureBeingParsed)->setType(data[0]);
        bType = false;
    }
    else if (bHpMoves)
    {
        std::dynamic_pointer_cast<Player>(creatureBeingParsed)->setHpMoves(std::stoi(data));
        bHpMoves = false;
    }
    else if (bItemIntValue)
    {
        itemBeingParsed->setItemIntValue(std::stoi(data));
        bItemIntValue = false;
    }
    else if (bActionMessage) // todo
    {
        //actionBeingParsed->setMessage(data);
        bActionMessage = false;
    }
    else if (bActionIntValue) // todo
    {
        //actionBeingParsed->setInValue(std::stoi(data));
        bActionIntValue = false;
    }
    else if (bActionCharValue) // todo
    {
        //actionBeingParsed->setCharValue(std::stoi(data));
        bActionCharValue = false;
    }

    char *qNameStr = xercesc::XMLString::transcode(qName);
    if (case_insensitive_match(qNameStr, "Dungeon"))
    {
        std::cout << dungeonBeingParsed->toString() << std::endl;
        dungeonBeingParsed = nullptr;
    }
    else if (case_insensitive_match(qNameStr, "Room"))
    {
        dungeonBeingParsed->addRoom(std::dynamic_pointer_cast<Room>(structureBeingParsed));
        structureBeingParsed = nullptr;
        displayablesBeingParsed.pop();
    }
    else if (case_insensitive_match(qNameStr, "Passage"))
    {
        dungeonBeingParsed->addPassage(std::dynamic_pointer_cast<Passage>(structureBeingParsed));
        structureBeingParsed = nullptr;
        displayablesBeingParsed.pop();
    }
    else if (case_insensitive_match(qNameStr, "Monster"))
    {
        dungeonBeingParsed->addMonster(std::dynamic_pointer_cast<Monster>(creatureBeingParsed));
        structureBeingParsed->addMonster(std::dynamic_pointer_cast<Monster>(creatureBeingParsed));
        creatureBeingParsed = nullptr;
        displayablesBeingParsed.pop();
    }
    else if (case_insensitive_match(qNameStr, "Player"))
    {
        dungeonBeingParsed->addPlayer(std::dynamic_pointer_cast<Player>(creatureBeingParsed));
        structureBeingParsed->addPlayer(std::dynamic_pointer_cast<Player>(creatureBeingParsed));
        creatureBeingParsed = nullptr;
        displayablesBeingParsed.pop();
    }
    else if (case_insensitive_match(qNameStr, "Scroll"))
    {
        dungeonBeingParsed->addItem(itemBeingParsed);
        structureBeingParsed->addItem(itemBeingParsed);
        itemBeingParsed = nullptr;
        displayablesBeingParsed.pop();
    }
    else if (case_insensitive_match(qNameStr, "Armor"))
    {
        dungeonBeingParsed->addItem(itemBeingParsed);
        structureBeingParsed->addItem(itemBeingParsed);
        itemBeingParsed = nullptr;
        displayablesBeingParsed.pop();
    }
    else if (case_insensitive_match(qNameStr, "Sword"))
    {
        dungeonBeingParsed->addItem(itemBeingParsed);
        structureBeingParsed->addItem(itemBeingParsed);
        itemBeingParsed = nullptr;
        displayablesBeingParsed.pop();
    }
    else if (case_insensitive_match(qNameStr, "CreatureAction"))
    {
        actionBeingParsed = nullptr;
    }
    else if (case_insensitive_match(qNameStr, "ItemAction"))
    {
        actionBeingParsed = nullptr;
    }

    xercesc::XMLString::release(&qNameStr);
}

void XMLHandler::characters(const XMLCh *const ch, const XMLSize_t length)
{
    data = xmlChToString(ch, (int)length);
    if (DEBUG > 1)
    {
        std::cout << CLASSID + ".characters: " << data << std::endl;
        std::cout.flush();
    }
}

void XMLHandler::fatalError(const xercesc::SAXParseException &exception)
{
    char *message = xercesc::XMLString::transcode(exception.getMessage());
    std::cout << "Fatal Error: " << message
              << " at line: " << exception.getLineNumber()
              << std::endl;
    xercesc::XMLString::release(&message);
}