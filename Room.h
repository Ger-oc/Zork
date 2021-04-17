#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include "item.h"


using namespace std;
using std::vector;
using std::map;
//int currentlocation;
class Room {

private:

    string description;
    map<string, Room*> exits;
    string exitString();
    vector <Item> itemsInRoom;
   std::map<std::string, int>moving;
    //moving.insert(pair("hall", 1));
   // moving.insert(std::make_pair("earth",1));
public:
    int currentlocation;
    int numberOfItems();
    Room(string description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription();
    /*void Room::testFunction();*/
    string longDescription();
    Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    void displayName();
    int currentRoom(int room);

    string shortDescription(string X);


    void setExits1(int, int, int, int);
};

#endif