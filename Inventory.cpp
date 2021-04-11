//
// Created on 05/04/2021.
//

#include "Inventory.h"
#include "Command.h"
#include "CommandWords.h"
#include "Room.h"

vector<string> ItemsOnPerson;
vector<string> Inventory::validItems;
string items[15];

Inventory::Inventory() {
// this creates the list of valid items a person can have on them
    if (validItems.empty()) {
        validItems.push_back("Magazine"); // from bed side locker
        validItems.push_back("bottle");  // from globe bar
        validItems.push_back("torch");  // torch to look under bed with
        validItems.push_back("book");    // found in suitcase in closet
        validItems.push_back("lighter"); // found in suitcase clothes
        validItems.push_back("sunscreen");  // found in suitcase usless item that they can pick up
        validItems.push_back("marbles");  //marbles from behind painting
        validItems.push_back("key"); // comes from cabinet
        validItems.push_back("umbrella");  //comes from umbrella stand in hallway
        validItems.push_back("book");   // to be used to open bok case drawer in hallway
        validItems.push_back("paper"); // paper from book case with a bit of the code
        validItems.push_back("screwdriver"); // to remove mirror
        validItems.push_back("toothbrush");  // from bathroom vanity useless
        validItems.push_back("razor"); // from bathroom vanity useless
        validItems.push_back(""); //

    }
}

/*string Inventory::takeItem(string item){




}*/


void Inventory::itemsList(int items[], int sizeofArray){

    for (int x = 0 ; x < sizeofArray; x++){
        cout << items[x] << endl;
    }
}


/*string Command::getSecondWord(){     NOT WORKING

    for (int i = 0; i < validItems.size(); ++i) {

        if(validItems[i].compare(getSecondWord()) == 0)
            ItemsOnPerson.push_back(validItems[i]);
    }
}
*/

