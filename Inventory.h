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
    static const int max = 15;
    vector<string> validItems;
    //string *validItems[max];


public:

    Inventory();
    string takeItem(string *item);
    void itemsList(int *items, int sizeofArray);
    void addItem(string item);
    int itemInInventory(string item);
    void showItems();

};


#endif //UNTITLED1_INVENTORY_H
