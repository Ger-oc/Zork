
#include "Inventory.h"
#include "Command.h"
#include "CommandWords.h"
#include "Room.h"

 vector<string> validItems;


Inventory::Inventory() {
    if(validItems.empty());

}

string Inventory::takeItem(string item) {
    int location = itemInInventory(item);
    if (location != -1) {
        validItems.erase(validItems.begin() + location);
        return item;
    }
    else {
        cout << "item is not in inventory" << endl;
        return "NOT_FOUND";
    }
}

void Inventory::showItems() {
    cout << "Inventory:" << endl;
   //for (int x = 0; x < validItems.size(); x++) {
     for(auto  x = validItems.begin(); x != validItems.end(); x++) {
          std::cout << *x + " ";
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

string Inventory::hiddenItems() {
   string secretItems[] = {"apple", "gameboy", "ice cream", "rug", "key", "laptop", "phone", "underpants", "pot", "pan", "cat food"};
    return 0;
}

void Inventory::showHiddenItems() {
    for( int i = 11; i < 11; ++i ){
        cout << secretItems[i-1] << " ";

    }
    cout<< "working"<< endl;
}