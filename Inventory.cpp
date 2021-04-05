//
// Created on 05/04/2021.
//

#include "Inventory.h"

vector<string> Inventory::validItems;

Inventory::Inventory(){

    if(validItems.empty()){
        validItems.push_back("Magazine");
        validItems.push_back("Magazine");
    }

}