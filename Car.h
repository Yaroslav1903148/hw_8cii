#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car();
	Car(int num, string model, int speed, string color, float price, int year);
	void showInfo()const override;
	void save(ostream& file)const override;
	void load(ifstream& file) override;
};

