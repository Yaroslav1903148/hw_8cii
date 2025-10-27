#include "Garage.h"



Garage::Garage(ifstream& fileCar, ifstream& fileBike, ifstream& fileLorry)
{
	if (!fileCar.is_open() || !fileBike.is_open() || !fileLorry.is_open()) {
		cout << "Error!\n";
		return;
	}

	Car* ptr = new Car();
	ptr->load(fileCar);
	arr.push_back(ptr);

	Bicycle* ptr1 = new Bicycle();
	ptr1->load(fileBike);
	arr.push_back(ptr1);

	Lorry* ptr2 = new Lorry();
	ptr2->load(fileLorry);
	arr.push_back(ptr2);

	fileCar.close();
	fileBike.close();
	fileLorry.close();
}

void Garage::addNew(ifstream& fileRead)
{

    if (!fileRead.is_open()) {
        cout << "Error!";
        return;
    }
    streampos pos = fileRead.tellg();

    string label;
    getline(fileRead, label);

    fileRead.seekg(pos);


    if (label == "Car") {
        Car* ptr = new Car();
        ptr->load(fileRead);
        arr.push_back(ptr);
    }
    else if (label == "Bicycle") {
        Bicycle* ptr = new Bicycle();
        ptr->load(fileRead);
        arr.push_back(ptr);
    }
    else if (label == "Lorry") {
        Lorry* ptr = new Lorry();
        ptr->load(fileRead);
        arr.push_back(ptr);
    }
    else {
        cout << "Error name: " << label << endl;
    }

    fileRead.close();
}

void Garage::delBynum(int num)
{
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]->getNum() == num) {
            delete arr[i];
            arr.erase(arr.begin() + i);
            cout << num << " deleted!\n";
        }

    }
}

void Garage::seaByModel(string model)
{
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]->getModel() == model) {
            cout << "Found!";
            arr[i]->showInfo();
        }
    }
}

void Garage::seaByNub(int num)
{
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]->getNum() == num) {
            cout << "Found!";
            arr[i]->showInfo();
        }
    }
}

void Garage::seaByTandSped(string model, int speed)
{
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]->getModel() == model && arr[i]->getSpeed() == speed ) {
            cout << "Found!";
            arr[i]->showInfo();
        }
    }
}

void Garage::editB(string model,  int num, string color, int speed)
{
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]->getModel() == model) {
            arr[i]->setNum(num);
            arr[i]->setColor(color);
            arr[i]->setSpeed(speed);
            cout << "Edited!\n";
            arr[i]->showInfo();
        }
    }
}

void Garage::sortBySpeed()
{
   sort(arr.begin(), arr.end(),[](const Vehicle* a, const Vehicle* b) {return a->getSpeed() < b->getSpeed(); });
   cout << "Sorted!";
   for (int i = 0; i < arr.size(); i++) {
       (*arr[i]).showInfo();
   }
}




void Garage::showInfo() const
{
	cout << "\n-----------------------Arr---------------------------\n";
	for (int i = 0; i < arr.size(); i++) {
		(*arr[i]).showInfo();
	}
}

