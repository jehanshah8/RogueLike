#ifndef XMLHANDLER_H_
#define XMLHANDLER_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <memory>
#include <stack>

#include "Dungeon.hpp"
#include "ObjectDisplayGrid.hpp"

#include "Displayable.hpp"

#include "Structures/Structure.hpp"
#include "Structures/Room.hpp"
#include "Structures/Passage.hpp"

#include "Creatures/Creature.hpp"
#include "Creatures/Player.hpp"
#include "Creatures/Monster.hpp"

#include "Items/Item.hpp"
#include "Items/Scroll.hpp"
#include "Items/Armor.hpp"
#include "Items/Sword.hpp"

#include "Magic/Magic.hpp"

#include "Actions/Action.hpp"

#include "Actions/Remove.hpp"
#include "Actions/YouWin.hpp"
#include "Actions/UpdateDisplay.hpp"
#include "Actions/Teleport.hpp"
#include "Actions/ChangeDisplayedType.hpp"
#include "Actions/EndGame.hpp"
#include "Actions/DropPack.hpp"

#include "Actions/BlessCurseOwner.hpp"
#include "Actions/Hallucinate.hpp"

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax2/Attributes.hpp>

class XMLHandler : public xercesc::DefaultHandler
{
private:
    int DEBUG = 1;
    std::string CLASSID = "XMLHandler";
    std::string data;

    std::shared_ptr<Dungeon> dungeonBeingParsed;
    std::stack<std::shared_ptr<Displayable>> displayablesBeingParsed;
    std::shared_ptr<Structure> structureBeingParsed;
    std::shared_ptr<Creature> creatureBeingParsed;
    std::shared_ptr<Item> itemBeingParsed;
    std::shared_ptr<Action> actionBeingParsed;
    std::string ActionType;

    // Shared among Room, Passage, Monster, Player, Items
    bool bVisible = false;
    bool bPosX = false;
    bool bPosY = false;

    // Room only
    bool bWidth = false;
    bool bHeight = false;

    // Monster & Player
    bool bHp = false;
    bool bMaxHit = false;

    // Monster only
    bool bType = false;

    // Player only
    bool bHpMoves = false;

    // Items
    bool bItemIntValue = false;

    // Actions (common for all Creatures and Items)
    bool bActionMessage = false;
    bool bActionIntValue = false;
    bool bActionCharValue = false;

public:
    virtual std::shared_ptr<Dungeon> getDungeon();
    void startElement(const XMLCh *uri, const XMLCh *localName, const XMLCh *qName, const xercesc::Attributes &attributes);
    void endElement(const XMLCh *uri, const XMLCh *localName, const XMLCh *qName);
    void characters(const XMLCh *const ch, const XMLSize_t length);
    void fatalError(const xercesc::SAXParseException &);
    //std::string toString();
};

#endif /* XMLHANDLER_H_ */
