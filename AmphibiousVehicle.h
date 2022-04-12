//AmphibiousVehicle.h - class declaration for an amphibious vehicle

#ifndef _AMPHIBIOUSVEHICLE_H_
#define _AMPHIBIOUSVEHICLE_H_

#include <iostream>
#include "Boat.h"
#include "Automobile.h"

class AmphibiousVehicle:public Boat, public Automobile {
	std::string name;
	unsigned short mode=VEHICLE_NONE;
public:
	static const unsigned short VEHICLE_NONE=0x00;
	static const unsigned short VEHICLE_AUTOMOBILE=0x01;
	static const unsigned short VEHICLE_BOAT=0x10;

    
	AmphibiousVehicle(std::string name, double fuelFfficiency, double AutoFuelinTank, double LitresPerHour, double BoatTankFuel) : 
	Automobile(name, fuelFfficiency, AutoFuelinTank), Boat(name, LitresPerHour, BoatTankFuel) {
		this->name=name;
	}
	Err_Status Travel(double _distance);
	Err_Status AddFuel(double amount);

	std::string GetName(){
		return this->name;
	}
	double GetFuel(){
		double boatFuel=Boat::GetFuel();
		double autoFuel=Automobile::GetFuel();
		return autoFuel+boatFuel;
	}
	double GetCost(){
		double autoCost=Automobile::GetCost();
		double boatCost=Boat::GetCost();
		return autoCost+boatCost;
	}


	void SetMode(unsigned short flag){
		mode=mode|flag;
	}
	void UnsetMode(unsigned short flag){
		mode = mode & ~flag;
	}

};

#endif// _AMPHIBIOUSVEHICLE_H_