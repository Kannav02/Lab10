#include "Automobile.h"

Vehicle::Err_Status Automobile::Travel(double _distance){
    //      Travel should accept distance as an argument and return an error status. Based on the 
	//      distance travelled and the fuel efficiency, one can calculate the amount of fuel consumed.
	//      If the fuel consumed is greater than the fuel in the tank, an exception is thrown with the message:
	//      "Automobile out of fuel".
	//      If there is enough fuel, decrease the fuel in the tank by the fuel consumed, and calculate the cost of the travel. Print out 
	//      a message showing how much fuel is left in the tank, how far the automobile travelled, and the cost of the travel.
	
        if(this->fuelEfficiency*(_distance/100.0)>FuelinTank){
            throw Err_Status::Err_OutOfFuel;
        }
        this->FuelinTank-=this->fuelEfficiency*(_distance/100.0);
        std::cout<<this->name<<" Automobile has "<<FuelinTank<<"L of Fuel Left in tank,It has travelled "<<_distance<< " km at a cost of $"<<fuelEfficiency*(_distance/100.0)*COST;

    // catch(Err_Status& a){
    //     std::cout<<"Automobile Out Of Fuel"<<std::endl;
    //     return Err_Status::Err_OutOfFuel;

    // }
    return Err_Status::Err_Success;
}

Vehicle::Err_Status Automobile::AddFuel(double amount){
	double amountAdded=0;
    if(this->FuelinTank+amount>TCAPACITY){
        amountAdded=TCAPACITY-FuelinTank;
        accumalatedCost+=amountAdded*COST;
        this->FuelinTank=50.0;
        std::cerr<<this->name<<" Has encountered a fuel overflow the amount added is actually "<<amountAdded<<" L at a cost of $"<<amountAdded*COST<<std::endl;
        return Err_Status::Err_FuelOverflow;
    }
    this->FuelinTank+=amount;
    amountAdded=FuelinTank-amount;
    accumalatedCost+=amountAdded*COST;
    std::cout<<this->name<<" Has been added a fuel of  "<<amountAdded<<" L at a cost of "<<this->GetCost();
    return Err_Status::Err_Success;


}
Automobile::Automobile(std::string _name ,double _FuelEfficiency ,double initialFuel){
	this->name=_name;
	this->fuelEfficiency=_FuelEfficiency;
	this->FuelinTank=initialFuel;
	this->accumalatedCost=(this->FuelinTank*COST);
	std::cout << name <<" automobile has added " << initialFuel << "L at a cost of $" <<accumalatedCost << "." << std::endl;
    std::cout<<std::endl;
}
