#pragma once
#ifndef Date_H_
#define Date_H_


#include <iostream>
#include "Date.h"
#include "ZorkUL.h"

using namespace std;

// first base class
class Date {
public:


private:
    friend class ZorkUL;
    //Date();

    string getDate();
    string generateDate();
    //string to_string();
};


#endif