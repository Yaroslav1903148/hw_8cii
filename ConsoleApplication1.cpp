#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Lorry.h"
#include "Bicycle.h"
#include "Garage.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    Car a(1, "Ford", 12321, "Focus", 12321312, 12312);
    Bicycle b(2, "Giant", 12321, "Escape", 12321312, 12312);
    Lorry c(3, "Volvo", 12321, "FH16", 12321312, 12312);

    ofstream fileCar("car.txt");
    a.save(fileCar);
    fileCar.close();

    ofstream fileBike("bicycle.txt");
    b.save(fileBike);
    fileBike.close();

    ofstream fileLorry("lorry.txt");
    c.save(fileLorry);
    fileLorry.close();

    cout << "Done saving!\n";

    ifstream fileCarIn("car.txt");
    ifstream fileBikeIn("bicycle.txt");
    ifstream fileLorryIn("lorry.txt");

    Garage g(fileCarIn, fileBikeIn, fileLorryIn);
    g.showInfo();
    cout << "\n=================================================================================================================\n";
    Lorry e(4, "Volvo", 123425123, "FH17", 12321312, 12312);
    ofstream filelo1("lorry1.txt");
    e.save(filelo1);
    filelo1.close();

    ifstream fileLor1In("lorry1.txt");
    g.addNew(fileLor1In);
    g.showInfo();
    cout << "\n------------------------------------------\n";
    g.delBynum(4);
    g.showInfo();
    cout << "\n=================================================================================================================\n";
    g.seaByModel("Ford");
    g.seaByNub(3);
    g.seaByTandSped("Volvo", 12321);
    cout << "\n=================================================================================================================\n";
    g.editB("Ford", 11, "Whitee", 250);
    g.editB("Giant", 12, "Whitee", 200);
    g.editB("Volvo", 10, "Whitee", 280);
    cout << "\n=================================================================================================================\n";
    g.sortBySpeed();
}

