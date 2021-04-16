
#include "Inventory.h"
#include "Command.h"
#include "CommandWords.h"
#include "Room.h"

//vector<string> Inventory::validItems;
int count = 0;

Inventory::Inventory() {
    // this creates the list of valid items a person can have on them
    string validItems[15];

}

string Inventory::takeItem(string *item) {
    int location = itemInInventory(*item);
    if (location != -1) {
        //for (int x = 0; x < max; x++){
            validItems[count] = item;
            count ++;
       // }
        //validItems.erase(validItems.begin() + location);
        return *item;
    }
    else {
        cout << "item is not in inventory" << endl;
        return "NOT_FOUND";
    }
}

void Inventory::showItems() {
    cout << "Inventory:" << endl;
    for (int x = 0; x < validItems.size(); x++) {
        cout << validItems[x] + " ";
    }
    cout << "" << endl;
}

int Inventory::itemInInventory(string item) {

    for (int x = 0; x < validItems.size(); x++) {
        if (item.compare(validItems[x]) == 0) {
            return x;
        }
    }
    return -1;
}

void Inventory::itemsList(int items[], int sizeofArray) {

    for (int x = 0; x < sizeofArray; x++) {
        cout << items[x] << endl;
    }
}

void Inventory::addItem(string item) {
    validItems.push_back(item);
}


/*string Command::getSecondWord(){     NOT WORKING

	for (int i = 0; i < validItems.size(); ++i) {

		if(validItems[i].compare(getSecondWord()) == 0)
			ItemsOnPerson.push_back(validItems[i]);
	}
}
*/

/*validItems.push_back("Magazine"); // from bed side locker
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
    validItems.push_back("");     */