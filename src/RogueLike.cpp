#include <iostream>
#include <string>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <exception>

#include "XMLHandler.hpp"
#include "Dungeon.hpp"
std::atomic_bool isRunning(true);

int main(int argc, char *argv[])
{

    std::string fileName;
    try
    {
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException &toCatch)
    {
        char *message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Error during initialization! :\n";
        std::cout << "Exception message is: \n"
                  << message << "\n";
        xercesc::XMLString::release(&message);
        return 1;
    }
    switch (argc)
    {
    case 2:
        fileName = "./xmlfiles/" + ((std::string)argv[1]);
        break;
    default:
        std::cout << "C++ Test <xmlfilename>" << std::endl;
    }
    xercesc::SAX2XMLReader *parser = xercesc::XMLReaderFactory::createXMLReader();

    try
    {
        XMLHandler *handler = new XMLHandler();
        parser->setContentHandler(handler);
        parser->setErrorHandler(handler);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreValidation, true);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreNameSpaces, true);
        XMLCh *fileNameXMLEnc = xercesc::XMLString::transcode(fileName.c_str()); //Encode string as UTF-16, but transcode needs casting as const char * (not std::string)
        parser->parse(fileNameXMLEnc);
        xercesc::XMLString::release(&fileNameXMLEnc);

        // Finished parsing, intialising display
        std::shared_ptr<Dungeon> dungeon = handler->getDungeon();
        //std::cout << dungeon->toString() << std::endl;


        dungeon->startGame();        
        delete parser;
        delete handler;
    }
    catch (const xercesc::XMLException &toCatch)
    {
        char *message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Exception message is: \n"
                  << message << "\n";
        xercesc::XMLString::release(&message);
        return -1;
    }
    catch (const xercesc::SAXParseException &toCatch)
    {
        char *message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Exception message is: \n"
                  << message << "\n";
        xercesc::XMLString::release(&message);
        return -1;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (...)
    {
        std::cout << "Unexpected Exception \n";
        return -1;
    }
    xercesc::XMLPlatformUtils::Terminate(); //valgrind will say there's memory errors if not included
    return 0;
}
