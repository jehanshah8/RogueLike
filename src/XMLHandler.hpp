#ifndef XMLHANDLER_H_
#define XMLHANDLER_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

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

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax2/Attributes.hpp>

class XMLHandler : public xercesc::DefaultHandler{
private:
    int DEBUG = 1;
    std::string CLASSID = "XMLHandler";
    std::string data ;
    std::vector<Student> students;
    int maxStudents = 0;
    int studentCount = 0;
    Student * studentBeingParsed ;
    Activity * activityBeingParsed ;
    bool bInstructor = false;
    bool bCredit = false;
    bool bName = false;
    bool bNumber = false;
    bool bLocation = false;
    bool bMeetingTime = false;
    bool bMeetingDay = false;
    void addStudent(Student student);

public:
    std::vector<Student>getStudents();
    StudentXMLHandler();
    void startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes) ;
    void endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName) ;
    void fatalError(const xercesc::SAXParseException&);
    void characters(const XMLCh * const ch, const XMLSize_t length ) ;
    std::string toString();


};

#endif /* XMLHANDLER_H_ */
