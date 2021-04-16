//
// Created by spike on 13/04/2021.
//


#include <iostream>

using namespace std;
#include "ZorkUL.h"
#include "Office.h"
#include "Bathroom.h"
#include "Bedroom.h"
#include "Hallway.h"
#include "item.h"
#include "Inventory.h"

string creators = "Marle + Gerard";
Inventory* inv;

ZorkUL::ZorkUL() {
    createRooms();
    inv = new Inventory();
}


void ZorkUL::createRooms() {
    Room* hall, * bathroom, * bedroom, * office, * extra;

    Hallway* ha = new Hallway();
    ha->setExits(office, bathroom, NULL, bedroom );
    ha->addItem(new Item("spoon", 1, 1.0));
    ha->addItem(new Item ("knife", 1, 1.0));
    ha->shortDescription("hallway");
    string test1 = ha->displayItem();
   // cout << test1 << endl;

    Bedroom* be = new Bedroom();
    be->setExits(NULL, NULL, hall, NULL);
    be->addItem(new Item("umbrella stand,", 1, 1.0));
    be->addItem(new Item("lamp", 1, 1.0));
    string test = be->displayItem();
    //cout << test << endl;

    Bathroom* ba = new Bathroom();
    ba->setExits(NULL, NULL, hall, NULL);
    ba->addItem(new Item("toilet", 1, 1.0));
    ba->addItem(new Item ("gold", 1, 1.0));
    string test2 = ba->displayItem();
   // cout << test2 << endl;

    Office* of = new Office();
    of->setExits(NULL, NULL, hall, NULL);
    of->addItem(new Item("money", 1, 1.0));
    of->addItem(new Item("cat",1, 1.0));
    string test3 = of->displayItem();
    //cout << test3 << endl;


    /*    Room hallway;
        hallway.shortDescription();
        hallway.numberOfItems();
        hallway.setExits(office, bathroom, NULL, bedroom);
        hallway.addItem((Item*)("lamp"));
       */
    /*hall = new Room("hallway");
    hall->numberOfItems();
    hall->addItem(new Item("umbrella stand,", 1, 1.0));
    hall->addItem(new Item("bust,", 2, 2.0));
    hall->addItem(new Item("book case,", 3, 3.0));
    hall->addItem(new Item("lamp,", 4, 4.0));
    hall->addItem(new Item("grandfather clock.", 5, 5.0));
    //hall->testFunction();

    bathroom = new Room("bathroom");
    bathroom->addItem(new Item("toilet,"));
    bathroom->addItem(new Item("gold bidet,"));
    bathroom->addItem(new Item("mirror,"));
    bathroom->addItem(new Item("vanity,"));
    bathroom->addItem(new Item("shower,"));
    bathroom->addItem(new Item("wall switch,"));
    bathroom->addItem(new Item("pull cord."));
    bathroom->addItem(new Item("toothbrush."));

    bedroom = new Room("bedroom");
    bedroom->addItem(new Item("bed,"));
    bedroom->addItem(new Item("closet,"));
    bedroom->addItem(new Item("big painting,"));
    bedroom->addItem(new Item("globe bar,"));
    bedroom->addItem(new Item("cabinet,"));

    office = new Room("office");
    office->addItem(new Item("Gold Buddha."));

    extra = new Room("e");
    extra->addItem(new Item("nothing"));*/


    //             (N, E, S, W)
   // hall->setExits(office, bathroom, NULL, bedroom);
   // bathroom->setExits(NULL, NULL, hall, NULL);
    //bedroom->setExits(NULL, NULL, hall, NULL);
    //office->setExits(NULL, NULL, hall, NULL);
    //  extra->setExits(NULL, NULL, NULL, NULL);
    /*f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);*/

    currentRoom = ha;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    //    Bedroom obj;
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    cout << "start" << endl;
    cout << "info for help" << endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input" << endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
    {
        cout << "              [Office]                 " << endl;
        cout << "                  |                    " << endl;
        cout << "                  |                    " << endl;
        cout << "[Bedroom] --- [Hallway] --- [Bathroom] " << endl;
    }

    else if (commandWord.compare("go") == 0)
        goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
            cout << "incomplete input" << endl;
        }
        else {
            string item = command.getSecondWord();
            cout << "you're trying to take " + item << endl;
            int location = currentRoom->isItemInRoom(item);

            if (location != -1) {
                inv->showItems();
                cout << "Found " + item + ". Putting it in inventory." << endl;
                inv->addItem(item);
                inv->showItems();
            }
            else {
                cout << "Cannot find " + item + " in this room." << endl;
            }

            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
        if (!command.hasSecondWord()) {
            cout << "incomplete input" << endl;
        }
        else
        {
            inv->showItems();

            string item = inv->takeItem(command.getSecondWord());

            if (item != "NOT_FOUND") {
                cout << "Took " + item << endl;
                currentRoom->addItem(new Item(item));
            }
            else
                cout << "Item is not here: " + item << endl;

            cout << currentRoom->longDescription() << endl;
            inv->showItems();
        }


    {
        /* if (!command.hasSecondWord()) {
             cout << "incomplete input"<< endl;
             }
             else
                 if (command.hasSecondWord()) {
                 cout << "you're adding " + command.getSecondWord() << endl;
                 itemsInRoom.push_Back;
             }
         }/*

     else if (commandWord.compare("quit") == 0) {
         if (command.hasSecondWord())
             cout << "overdefined input" << endl;
         else
             return true; /**signal to quit*/
    }
    return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input" << endl;
        return;
    }

    string direction = command.getSecondWord();
    direction[0] = ::tolower(direction[0]);

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input" << endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
    }
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return ("direction null");
    else {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

void ZorkUL::deletItem() {


}

/*void ZorkUL::addItemToInventory(string theItem) {
	itemsinInventory.push_back(theItem);


}*/
