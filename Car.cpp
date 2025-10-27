#include "Car.h"


Car::Car():Vehicle()
{
}

Car::Car(int num, string model, int speed, string color, float price, int year) :Vehicle(num, model, speed, color, price, year)
{
}


void Car::showInfo() const
{
    cout << "\n======================Car===========================\n";
    cout << "\tNumber: " << num << endl;
    cout << "\tModel: " << model << endl;
    cout << "\tSpeed: " << speed << endl;
    cout << "\tColor: " << color << endl;
    cout << "\tPrice: " << price << endl;
    cout << "\tYear: " << year << endl;
    cout << "\n====================================================\n";
}

void Car::save(ostream& file) const
{
    file << "Car\n" << num << endl << model << endl << speed << endl << color << endl << price << endl << year << endl;
}

void Car::load(ifstream& file)
{
    string label;
    file >> label;
    file >> num;
    file.ignore(); 
    getline(file, model);
    file >> speed;
    file.ignore();
    getline(file, color);
    file >> price;
    file >> year;
}
