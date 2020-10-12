#ifndef XMLHANDLER_H_
#define XMLHANDLER_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

/**
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

#include "Actions/CreatureActions/CreatureAction.hpp"
#include "Actions/CreatureActions/Remove.hpp"
#include "Actions/CreatureActions/YouWin.hpp"
#include "Actions/CreatureActions/UpdateDisplay.hpp"
#include "Actions/CreatureActions/Teleport.hpp"
#include "Actions/CreatureActions/ChangeDisplayedType.hpp"
#include "Actions/CreatureActions/EndGame.hpp"
#include "Actions/CreatureActions/DropPack.hpp"

#include "Actions/ItemActions/ItemAction.hpp"
#include "Actions/ItemActions/BlessCurseOwner.hpp"
#include "Actions/ItemActions/Hallucinate.hpp"
*/

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax2/Attributes.hpp>

class XMLHandler : public xercesc::DefaultHandler{
private:
    int DEBUG = 1;
    std::string CLASSID = "XMLHandler";
    std::string data;

    //std::unique_ptr<Dungeon> dungeon_ptr; 
    
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

    //void addStudent(Student student);

public:
    //Dungeon& getDungeon();
    XMLHandler();
    void startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes);
    void endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName);
    void characters(const XMLCh * const ch, const XMLSize_t length );
    void fatalError(const xercesc::SAXParseException&);
    //std::string toString();
};

#endif /* XMLHANDLER_H_ */
