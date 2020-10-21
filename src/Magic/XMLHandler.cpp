#include "XMLHandler.hpp"

//helpers
//From https://www.tutorialspoint.com/case-insensitive-string-comparison-in-cplusplus
int case_insensitive_match(std::string s1, std::string s2) {
    //convert s1 and s2 into lower case strings
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower); //std overloads tolower, ::tolower is the definition in the global namespace
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if(s1.compare(s2) == 0)
        return 1;
    return 0;
}

inline std::string boolToString(bool booleanValue){
    return booleanValue ? "true": "false";
}

XMLHandler::XMLHandler() {

}

/**
Dungeon& XMLHandler::getDungeon() {
    return dungeon;
}
*/

std::string xmlChToString(const XMLCh* xmlChName, int length = -1){
    //Xerces Parses file into XMLCh* string. So use Transcode to allocate a char* buffer
    char * chStarName = xercesc::XMLString::transcode(xmlChName); 
    if(length == -1){
        std::string StrName(chStarName);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }
    else{
        std::string StrName(chStarName,0,length);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }

}

const XMLCh* getXMLChAttributeFromString(const xercesc::Attributes& attributes, const char * strGet){
    XMLCh * xmlChGet = xercesc::XMLString::transcode(strGet);
    const XMLCh * xmlChAttr = attributes.getValue(xmlChGet);
    xercesc::XMLString::release((&xmlChGet));
    return xmlChAttr;
}

void XMLHandler::startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes){

        char * qNameStr = xercesc::XMLString::transcode(qName);
        if (DEBUG > 1) {
            std::cout << CLASSID << ".startElement qName: " << qNameStr << std::endl;
        }

        if (case_insensitive_match(qNameStr, "Dungeon")) {
			std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int width = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"width")));
            int topHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"topHeight")));
            int gameHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"gameHeight")));
            int bottomHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"bottomHeight")));
            
            // printing for parsing and debugging only
            std::string str = "Dungeon: \n";
            str += "   name: " + name + "\n";
            str += "   width: " + std::to_string(width) + "\n";
            str += "   topHeight: " + std::to_string(topHeight) + "\n"; 
            str += "   gameHeight: " + std::to_string(gameHeight) + "\n";
            str += "   bottomHeight: " + std::to_string(bottomHeight) + "\n";   
            std::cout << str << std::endl;
            // end print

            //this->dungeon_ptr = std::unique_ptr<Dungeon>(new Dungeon(name, width, topHeight, gameHeight, bottomHeight)); 
        } else if (case_insensitive_match(qNameStr,"Rooms")) {
            std::cout << "Rooms\n" << std::endl;
        } else if (case_insensitive_match(qNameStr,"Room")) {
            int roomID = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room")));

            // printing for parsing and debugging only
            std::string str = "Room: \n";
            str += "   roomID: " + std::to_string(roomID) + "\n";
            std::cout << str << std::endl;
            // end print
        } else if (case_insensitive_match(qNameStr,"Passages")) {
            std::cout << "Passages\n" << std::endl;
        } else if (case_insensitive_match(qNameStr,"Passage")) {
            int room1 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room1")));
            int room2 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room2")));

            // printing for parsing and debugging only
            std::string str = "Passage: \n";
            str += "   room1: " + std::to_string(room1) + "\n";
            str += "   room2: " + std::to_string(room2) + "\n";
            std::cout << str << std::endl;
            // end print
        } else if (case_insensitive_match(qNameStr,"Monster")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));

            // printing for parsing and debugging only
            std::string str = "Monster: \n";
            str += "   name: " + name + "\n";
            str += "   room: " + std::to_string(room) + "\n";
            str += "   serial: " + std::to_string(serial) + "\n";
            std::cout << str << std::endl;
            // end print
        } else if (case_insensitive_match(qNameStr,"Player")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));

            // printing for parsing and debugging only
            std::string str = "Player: \n";
            str += "   name: " + name + "\n";
            str += "   room: " + std::to_string(room) + "\n";
            str += "   serial: " + std::to_string(serial) + "\n";
            std::cout << str << std::endl;
            // end print
        } else if (case_insensitive_match(qNameStr,"Scroll")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));

            // printing for parsing and debugging only
            std::string str = "Scroll: \n";
            str += "   name: " + name + "\n";
            str += "   serial: " + std::to_string(room) + "\n";
            str += "   serial: " + std::to_string(serial) + "\n";
            std::cout << str << std::endl;
            // end print
        } else if (case_insensitive_match(qNameStr,"Armor")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));

            // printing for parsing and debugging only
            std::string str = "Armor: \n";
            str += "   name: " + name + "\n";
            str += "   serial: " + std::to_string(room) + "\n";
            str += "   serial: " + std::to_string(serial) + "\n";
            std::cout << str << std::endl;
            // end print
        } else if (case_insensitive_match(qNameStr,"Sword")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "room")));
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes, "serial")));

            // printing for parsing and debugging only
            std::string str = "Sword: \n";
            str += "   name: " + name + "\n";
            str += "   serial: " + std::to_string(room) + "\n";
            str += "   serial: " + std::to_string(serial) + "\n";
            std::cout << str << std::endl;
            // end print
        } else if (case_insensitive_match(qNameStr,"CreatureAction")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            std::string type = xmlChToString(getXMLChAttributeFromString(attributes,"type"));

            // printing for parsing and debugging only
            std::string str = "CreatureAction: \n";
            str += "   name: " + name + "\n";
            str += "   type: " + type + "\n";
            std::cout << str << std::endl;
            // end print
        } else if (case_insensitive_match(qNameStr,"ItemAction")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            std::string type = xmlChToString(getXMLChAttributeFromString(attributes,"type"));

            // printing for parsing and debugging only
            std::string str = "ItemAction: \n";
            str += "   name: " + name + "\n";
            str += "   type: " + type + "\n";
            std::cout << str << std::endl;
            // end print
        } else if (case_insensitive_match(qNameStr,"visible")) {
            bVisible = true;
            //int visible = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"n")));
        } else if (case_insensitive_match(qNameStr,"posX")) {
            bPosX = true;
        } else if (case_insensitive_match(qNameStr,"posY")) {
            bPosY = true;
        } else if (case_insensitive_match(qNameStr,"width")) {
            bWidth = true;
        } else if (case_insensitive_match(qNameStr,"height")) {
            bHeight = true;
        } else if (case_insensitive_match(qNameStr,"hp")) {
            bHp = true;
        } else if (case_insensitive_match(qNameStr,"maxHit")) {
            bMaxHit = true;
        } else if (case_insensitive_match(qNameStr,"type")) {
            bType = true;
        } else if (case_insensitive_match(qNameStr,"hpMoves")) {
            bHpMoves = true;
        } else if (case_insensitive_match(qNameStr,"itemIntValue")) {
            bItemIntValue = true;
        } else if (case_insensitive_match(qNameStr,"actionMessage")) {
            bActionMessage = true;
        } else if (case_insensitive_match(qNameStr,"actionIntValue")) {
            bActionIntValue = true;
        } else if (case_insensitive_match(qNameStr,"actionCharValue")) {
            bActionCharValue = true;
        } else {
            std::cout <<"Unknown qname: " << qNameStr << std::endl;
        }
        xercesc::XMLString::release(&qNameStr);
}

void XMLHandler::endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName)  {
        std::cout << data << std::endl;
        //char *  qNameStr = xercesc::XMLString::transcode(qName);
        //xercesc::XMLString::release(&qNameStr);
}

void XMLHandler::characters(const XMLCh * const ch, const XMLSize_t length) {
        data = xmlChToString(ch,(int)length) ;   
        if (DEBUG > 1) {
			std::cout << CLASSID + ".characters: " << data << std::endl;
            std::cout.flush();
        }
}

void XMLHandler::fatalError(const xercesc::SAXParseException& exception)
{
    char* message = xercesc::XMLString::transcode(exception.getMessage());
    std::cout << "Fatal Error: " << message
         << " at line: " << exception.getLineNumber()
         << std::endl;
    xercesc::XMLString::release(&message);
}