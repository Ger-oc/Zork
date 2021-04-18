//
// Created by spike on 05/04/2021.
//

#ifndef UNTITLED1_INVENTORY_H
#define UNTITLED1_INVENTORY_H

#include <vector>
#include <string>
#include <array>
#include <iostream>



using namespace std;

class Inventory {

private:
   // static const int max = 15;
    vector<string> validItems;
    vector<string> ItemsOnPerson;
    const char *secretItems[11] = {"apple", "gameboy", "ice cream", "rug",
                               "key", "laptop", "phone", "underpants",
                               "pot", "pan", "cat food"};



public:

    Inventory();
    ~Inventory();
    string takeItem(string item);
    void itemsList(int *items, int sizeofArray);
    void addItem(string item);
    int itemInInventory(string item);
    void showItems();
    string hiddenItems();
    void showHiddenItems();
};


#endif //UNTITLED1_INVENTORY_H
