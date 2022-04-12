#include "AmphibiousVehicle.h"

Vehicle::Err_Status AmphibiousVehicle::Travel(double _distance){
	Vehicle::Err_Status e=Vehicle::Err_Status::Err_Success;
	if (this->mode==AmphibiousVehicle::VEHICLE_AUTOMOBILE){
		try{
			e=Automobile::Travel(_distance);
		}
		catch(Vehicle::Err_Status& e){
			std::cout<<"Automobile Out Of Fuel"<<std::endl;
			e=Err_Status::Err_OutOfFuel;

			}
			return e;
		}
	if (this->mode==VEHICLE_BOAT){
		try{
			e=Boat::Travel(_distance);
		}
		catch(Vehicle::Err_Status& e){
				std::cout<<"Boat Out Of Fuel"<<std::endl;
				e=Err_Status::Err_OutOfFuel;

			}
			return e;
		}
	else{
		std::cerr<<"No mode selected"<<std::endl;
		e=Err_Status::Err_IncorrectMode;
		return e;
	}

}
Vehicle::Err_Status AmphibiousVehicle::AddFuel(double amount){
		Vehicle::Err_Status e=Err_Status::Err_Success;
		if(this->mode==AmphibiousVehicle::VEHICLE_AUTOMOBILE){
			e=Automobile::AddFuel(amount);
		}
		if(this->mode==AmphibiousVehicle::VEHICLE_BOAT){
			e=Boat::AddFuel(amount);
		}
		else{
			e=Err_Status::Err_IncorrectMode;
			
			
		}
		return e;
}

