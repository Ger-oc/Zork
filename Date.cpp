#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string> 
#include "Date.h"
#include "ZorkUL.h"

using namespace std;

string Date::generateDate() {

    struct date {
        unsigned int tm_mday : 1;

        unsigned int tm_mon : 1;

        unsigned int tm_year : 2;
    };

    //printf("Size of date is %lu bytes\n",
    //sizeof(struct date));

    time_t now = time(0);

    tm* ltm = localtime(&now);

    string day = to_string(ltm->tm_mday);
    string month = to_string(1 + ltm->tm_mon);
    string year = to_string(1900 + ltm->tm_year);
    string date = (day + "-" + month + "-" + year);
    cout << date << endl;
    return date;
};

/*string Date::to_string(){
    return date;
}
*/

string Date::getDate() {
    string test = generateDate();
    return test;
}

