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
	void showInfo()const;
};

