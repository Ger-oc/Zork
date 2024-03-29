#include "Room.h"
#include "Command.h"

Room::Room(string description) {
    this->description = description;
}

int doorCode = 8521;
int& officeCode = doorCode;
string X;


void Room::setExits(Room *office, Room *bathroom, Room *hall, Room *bedroom) {
    if (office != NULL)
        exits["office"] = office;
    if (bathroom != NULL)
        exits["bathroom"] = bathroom;
    if (hall != NULL)
        exits["hall"] = hall;
    if (bedroom != NULL)
        exits["bedroom"] = bedroom;
}
/*void Room::setExits1(int , int, int, int) {
    if(currentlocation == 1){
        test =
    }

}*/

string Room::shortDescription( string X) {
    return X;
}

void Room::displayName() {
    cout << X << endl;
}
/*void Room::testFunction() {
    cout << "test test" << endl;
}*/

string Room::longDescription() {
    return "room = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
    string returnString = "\nexits =";
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
    // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}

string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());


    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
    }
    else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
        }
    }
    return tempString;
}

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
    }
    else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
        }
    }
    return -1;
}


void  Room::removeItemFromRoom(int location){
    int n=itemsInRoom.size();
    if(location>=1&&location<=n){
        itemsInRoom.erase(itemsInRoom.begin()+(location-1));
    }
    else{
        cout<<"no item in this position"<<endl;
    }
}

int Room::currentRoom(int room){
    currentlocation = room;
    return currentlocation;
}