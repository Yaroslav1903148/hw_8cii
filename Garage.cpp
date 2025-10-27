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

    string type;
    fileRead >> type;

    if (type == "Lorry") {
        Lorry* ptr = new Lorry();
        ptr->load(fileRead);
        arr.push_back(ptr);
    }
    else if (type == "Car") {
        Car* ptr = new Car();
        ptr->load(fileRead);
        arr.push_back(ptr);
    }
    else if (type == "Bicycle") {
        Bicycle* ptr = new Bicycle();
        ptr->load(fileRead);
        arr.push_back(ptr);
    }
    else {
        cout << "Error name: " << type << endl;
    }

    fileRead.close();
}


void Garage::showInfo() const
{
	cout << "\n-----------------------Arr---------------------------\n";
	for (int i = 0; i < arr.size(); i++) {
		(*arr[i]).showInfo();
	}
}

