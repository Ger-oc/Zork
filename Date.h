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
	friend class ZorkUL;
private:
	Date();
	//string to_string();
};


#endif