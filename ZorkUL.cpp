#include <iostream>
#include <vector>

using namespace std;
#include "Date.h"
#include "ZorkUL.h"
#include "Office.h"
#include "Bathroom.h"
#include "Bedroom.h"
#include "Hallway.h"
#include "item.h"
#include "Inventory.h"
const int MAX = 20;
string creators = "creators : Marle + Gerard";
Inventory* inv;

Date date;

ZorkUL::ZorkUL() {
    cout << "Today's date is: ";
    string test = date.getDate();
    cout << creators << endl;
    //cout << test << endl;
    createRooms();
    inv = new Inventory();

}


void ZorkUL::createRooms() {
    Room *hall, *bathroom, *bedroom, *office; // * extra = new Room("Hidden Room");

    hall = new Room("hall");
    hall->numberOfItems();
    hall->shortDescription("hall");
    hall->nextRoom("north");
    hall->addItem(new Item("bust"));
    hall->addItem(new Item("book case"));
    hall->addItem(new Item("umbrella stand"));
    hall->addItem(new Item("paper"));

    bathroom = new Room("bathroom");
    bathroom->addItem(new Item("toilet"));
    bathroom->addItem(new Item("gold bidet"));
    bathroom->addItem(new Item("mirror"));
    bathroom->addItem(new Item("screwdriver"));
    bathroom->addItem(new Item("shampoo"));

    bedroom = new Room("bedroom");
    bedroom->addItem(new Item("magazine"));
    bedroom->addItem(new Item("bed"));
    bedroom->addItem(new Item("suitcase"));
    bedroom->addItem(new Item("suncream"));
    bedroom->addItem(new Item("painting"));
    bedroom->addItem(new Item("marbles"));

    office = new Room("office");
    office->addItem(new Item("gold Buddha"));
    office->addItem(new Item("cash"));
    office->addItem(new Item("cat"));

    //             (N, E, S, W)
    hall->setExits(office, bathroom, NULL, bedroom);
    bathroom->setExits(NULL, NULL, hall, NULL);
    bedroom->setExits(NULL, NULL, hall, NULL);
    office->setExits(NULL, NULL, hall, NULL);



   currentRoom = hall;
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

    else if (commandWord.compare("map") == 0) {
        cout << "              [Office]                 " << endl;
        cout << "                  |                    " << endl;
        cout << "                  |                    " << endl;
        cout << "[Bedroom] --- [Hallway] --- [Bathroom] " << endl;
    } else if (commandWord.compare("go") == 0)
        goRoom(command);

    else if (commandWord.compare("take") == 0) {
        if (!command.hasSecondWord()) {
            cout << "incomplete input" << endl;
        } else {
            string item = command.getSecondWord();
            cout << "you're trying to take " + item << endl;
            int location = currentRoom->isItemInRoom(item);

            if (location != -1) {
                inv->showItems();
                cout << "Found " + item + ". Putting it in inventory." << endl;
                inv->addItem(item);
                inv->showItems();
            } else {
                cout << "Cannot find " + item + " in this room." << endl;
            }

            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    } else if (commandWord.compare("put") == 0)
        if (!command.hasSecondWord()) {
            cout << "incomplete input" << endl;
        } else {
            inv->showItems();
            string item = "";

            if (item != "NOT_FOUND") {
                cout << "Took " + item << endl;
                currentRoom->addItem(new Item(item));
            } else
                cout << "Item is not here: " + item << endl;

            cout << currentRoom->longDescription() << endl;
            inv->showItems();
        }
    else if (commandWord.compare("inventory") == 0) {
            inv->showItems();

        cout << "\n";
    } else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input" << endl;
        else
            return true;
    }
    return false;
}
        /* if (!command.hasSecondWord()) {
             cout << "incomplete input"<< endl;
             }
             else
                 if (command.hasSecondWord()) {
                 cout << "you're adding " + command.getSecondWord() << endl;
                 itemsInRoom.push_Back;
             }
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

/**void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()){
        cout << "incomplete input" << endl;
        return;
    }
    string direction = command.getSecondWord();
    if(direction == "office"){
        switch (north) {

        }
    }
}*/
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
