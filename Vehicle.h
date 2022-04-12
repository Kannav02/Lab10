//Vehicle.h - class declaration for an vehicle

#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>

class Vehicle {
public:
	enum class Err_Status {
		Err_Success,
		Err_OutOfFuel,
		Err_FuelOverflow,
		Err_IncorrectMode
		//TODO: Complete for out of fuel, fuel overflow, and incorrect mode
	};
	//TODO: Add function interfaces for travel, add fuel, get fuel and get cost.
	//      Travel takes distance as an argument and returns an error status
	virtual Err_Status Travel(double _distance)=0;
	//      AddFuel takes amount as an argument and returns an error status
	virtual Err_Status AddFuel(double amount)=0;
	//      GetFuel simply returns the amount of fuel left in the tank
	virtual double GetFuel()=0;
	//      GetCost simply returns the accumulated cost of all fuel purchases
	virtual double GetCost()=0;
};

#endif// _VEHICLE_H_