#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Car.h"
#include "Lorry.h"
#include "Bicycle.h"
#include "Vehicle.h"
using namespace std;
class Garage
{
private:
	vector<Vehicle*>arr;
public:
	Garage(ifstream& fileCar, ifstream&  fileBike, ifstream& fileLorry);

	void addNew(ifstream& fileRead);
	void delBynum(int num);
	void seaByModel(string model);
	void seaByNub(int num);
	void seaByTandSped(string model, int speed);
	void editB(string model, int num, string color, int speed);
	void sortBySpeed();
	void showInfo()const;
};

