//AmphibiousVehicleMain.cpp - main program for travelling with an amphibious vehicle

#include <iomanip>
#include <iostream>
#include "AmphibiousVehicle.h"

using namespace std;

int main() {
	Vehicle::Err_Status status;
	//TODO: Add a smart pointer of type AmphibiousVehicle. 
	//      Call the amphibious vehicle object "ampVehicle" and name this amphibious vehicle as "Hydra Spyder"
	unique_ptr<AmphibiousVehicle> ampVehicle (new AmphibiousVehicle("Hydra Spyder",10, 50, 20, 150));

	cout << "The automobile will travel 200km" << endl;
	ampVehicle->SetMode(AmphibiousVehicle::VEHICLE_AUTOMOBILE);
	status = ampVehicle->Travel(200.0);//travel 200km
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " automobile cannot travel 200km." << endl;
	cout << endl;
	
	cout << "The boat will travel 20km" << endl;
	ampVehicle->UnsetMode(AmphibiousVehicle::VEHICLE_AUTOMOBILE);
	ampVehicle->SetMode(AmphibiousVehicle::VEHICLE_BOAT);
	status = ampVehicle->Travel(20.0);//travel 20km
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " boat cannot travel 20km." << endl;
	cout << endl;

	cout << fixed;
	cout << setprecision(2);
	cout << ampVehicle->GetName() << " in total has spent $" << ampVehicle->GetCost() << " on fuel." << endl;
	cout << endl;

	//Add 30L of fuel to the boat and travel 200km
	cout << "Adding 30L of fuel to the boat" << endl;
	status = ampVehicle->AddFuel(30);
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " boat cannot add 30L of fuel." << endl;
	cout << endl;
	cout << "The boat will travel 200km" << endl;
	ampVehicle->Travel(200.0);
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " boat cannot travel 200km." << endl;
	cout << endl;

	//And 30L of fuel to the automobile and travel 300km
	ampVehicle->UnsetMode(AmphibiousVehicle::VEHICLE_BOAT);
	ampVehicle->SetMode(AmphibiousVehicle::VEHICLE_AUTOMOBILE);
	cout << "Adding 30L of fuel to the automobile" << endl;
	status = ampVehicle->AddFuel(30);
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " automobile cannot add 30L of fuel." << endl;
	cout << endl;
	cout << "The automobile will travel 300km" << endl;
	status = ampVehicle->Travel(300.0);
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " automobile cannot travel 300km." << endl;
	cout << endl;

	cout << ampVehicle->GetName() << " in total has spent $" << ampVehicle->GetCost() << " on fuel." << endl;
	cout << endl;

	return 0;
}
/*1. Multiple Inheritance Leads to a lot of ambiguity as in this problem we can see that in the following example

		A
	/		\
   B         C
	\       /
		D

A(Grandparent)-: Is Inherited Twice by the child class D due to the problem of D being a child of both Parent B and C
this leads to ambguity between calling the function and name conflicts which can lead to a programe crash

2.The diamond problem is solved by making the parent classes inherit the grandparent classes virtually in order to avoid two copies 
of grandparent class using the virtual keyword for the base class

3.earlier we use to solve the diamond problem by making the base class call in the parent function virtual , but here the base class itself is an abstract
virtual class , so the probelm itself gets solved without us declaring it or making it virtual during the call for parent functions
*/