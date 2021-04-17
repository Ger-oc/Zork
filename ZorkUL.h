#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Bathroom.h"
#include "Hallway.h"
#include "Office.h"
#include "Bedroom.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL  {
    friend class Room;
private:
    Parser parser;
    Room *currentRoom;
    void createRooms();
    void printWelcome();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems(string);
    void deletItem();

public:
    ZorkUL();
    void play();
    string go(string direction);


    void addItemToInventory();
};

#endif /*ZORKUL_H_*/
