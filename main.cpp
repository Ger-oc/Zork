
#include <iostream>

using namespace std;
#include "ZorkUL.h"

string creators = "Marle + Gerard";

int main()
{
    ZorkUL temp;
    temp.play();
    return 0;
}

ZorkUL::ZorkUL() {
    createRooms();
}


void ZorkUL::createRooms() {
    Room* hall, * bathroom, * bedroom, * office, * extra;

    hall = new Room("hallway");
    hall->addItem(new Item("umbrella stand,", 1, 11));
    hall->addItem(new Item("bust,", 2, 22));
    hall->addItem(new Item("book case,", 2, 22));
    hall->addItem(new Item("lamp,", 2, 22));
    hall->addItem(new Item("grandfather clock.", 2, 22));

    bathroom = new Room("bathroom");
    bathroom->addItem(new Item("toilet,", 3, 33));
    bathroom->addItem(new Item("gold bidet,", 4, 44));
    bathroom->addItem(new Item("mirror,", 4, 44));
    bathroom->addItem(new Item("vanity,", 4, 44));
    bathroom->addItem(new Item("shower,", 4, 44));
    bathroom->addItem(new Item("wall switch,", 4, 44));
    bathroom->addItem(new Item("pull cord.", 4, 44));

    bedroom = new Room("bedroom");
    bedroom->addItem( new Item("bed,", 3, 12));
    bedroom->addItem( new Item("closet,", 3, 12));
    bedroom->addItem( new Item("big painting,", 3, 12));
    bedroom->addItem( new Item("globe bar,", 3, 12));
    bedroom->addItem( new Item("cabinet,", 3, 12));

    office = new Room("office");
    office->addItem( new Item("Gold Buddha.", 999, 999));

    extra = new Room("e");
    extra->addItem(new Item("noting", 3, 3));


    //             (N, E, S, W)
    hall->setExits(office, bathroom,NULL , bedroom);
    bathroom->setExits(NULL, NULL, hall, NULL);
    bedroom->setExits(NULL, NULL, hall, NULL);
    office->setExits(NULL, NULL, hall, NULL);
    extra->setExits(NULL, NULL, NULL, NULL);
    /*f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);*/

    currentRoom = hall;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
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
        else
        if (command.hasSecondWord()) {
            cout << "you're trying to take " + command.getSecondWord() << endl;
            int location = currentRoom->isItemInRoom(command.getSecondWord());
            if (location < 0)
                cout << "item is not in room" << endl;
            else
                cout << "item is in room" << endl;
            cout << "index number " << +location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)




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
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}