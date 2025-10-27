#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle
{
protected:
	 int num;
	string model;
	int speed;
	string color;
	float price;
	int year;
public:
	Vehicle();
	Vehicle(int num, string model, int speed, string color, float price, int year);
	virtual ~Vehicle();

	void setNum(int num);
	void setModel(string model);
	void setSpeed(int speed);
	void setColor(string color);
	void setPrice(float price);
	void setYear(int year);
	
	int getNum()const;
	string getModel()const;
	int getSpeed()const;
	string getColor()const;
	float getPrice()const;
	int getYear()const;

	virtual void showInfo()const = 0;
	virtual void save(ostream& file)const = 0;
	virtual void load(ifstream& file) = 0;
};

