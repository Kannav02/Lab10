//Boat.h - class declaration for an boat

#ifndef _BOAT_H_
#define _BOAT_H_
#define CAPACITY 150.0
#define SPEED 20.0
#define AMOUNT 1.60

#include <iostream>
#include "Vehicle.h"

class Boat : public Vehicle {
	//TODO: Add variables for name, litres consumed per hour, fuel in the tank and accumulated cost
	std::string name;
	double LitresPerHour;
	double FuelinTank;
	double accumalatedCost;
	//      Assume the boat travels at a constant speed of 20.0 km/hour
	//      Assume the cost per litre of boat fuel is $1.60
	//      Assume the tank capacity is 150.0L
public:
    //TODO: Create a constructor that passes through the boat's name, the litres consumed per hour, 
	//      and the initial fuel in the tank. Be sure to initialize the cost based on this fuel.
	//      Print out a message indicating how much fuel has been added and its cost.
	Boat(std::string _name,double _Litres,double initialFuel);
	Err_Status Travel(double _distance);
	Err_Status AddFuel(double amount);
	double GetFuel();
	double GetCost();

};

#endif// _BOAT_H_
