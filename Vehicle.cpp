#include "Vehicle.h"

Vehicle::Vehicle()
{
    num = 0;
    model = "undf";
    speed = 0;
    color = "undf";
    price = 0;
    year = 0;
}

Vehicle::Vehicle(int num, string model, int speed, string color, float price, int year)
{
    this->num = num;
    this->model = model;
    this->speed = speed;
    this->color = color;
    this->price = price;
    this->year = year;
}

Vehicle::~Vehicle()
{
    cout << "~Vehicle()";
}

void Vehicle::setNum(int num)
{
    this->num = num;
}

void Vehicle::setModel(string model)
{
    this->model = model;
}

void Vehicle::setSpeed(int speed)
{
    this->speed = speed;
}

void Vehicle::setColor(string color)
{
    this->color = color;
}

void Vehicle::setPrice(float price)
{
    this->price = price;
}

void Vehicle::setYear(int year)
{
    this->year = year;
}

int Vehicle::getNum() const
{
    return num;
}

string Vehicle::getModel() const
{
    return model;
}

int Vehicle::getSpeed() const
{
    return speed;
}

string Vehicle::getColor() const
{
    return color;
}

float Vehicle::getPrice() const
{
    return price;
}

int Vehicle::getYear() const
{
    return year;
}

