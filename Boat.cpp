#include "Boat.h"

Boat::Boat(std::string _name,double _Litres,double initialFuel){
    this->name=_name;
    this->LitresPerHour=_Litres;
    this->FuelinTank=initialFuel;
    // Add variables for name, litres consumed per hour, fuel in the tank and accumulated cost.
    //  Assume the boat travels at a constant speed of 20.0 km/hour. Assume the cost per litre of boat fuel is $1.60. Assume the tank capacity is 150.0L.
// The constructor passes through the boat's name, the litres consumed per hour, and the initial fuel in the tank.
//  Be sure to initialize the cost based on this fuel.
//  Print out a message indicating how much fuel has been added and its cost.
    this->accumalatedCost=(this->FuelinTank*AMOUNT);
    std::cout << name <<" boat has added " << initialFuel << "L at a cost of $" <<accumalatedCost << "." << std::endl;
    std::cout<<std::endl;
}
Vehicle::Err_Status Boat::Travel(double _distance){
    double time =_distance/SPEED;
    
    if(this->LitresPerHour*time>FuelinTank){
            throw Err_Status::Err_OutOfFuel;
}
    this->FuelinTank-=this->LitresPerHour*time;
    std::cout<<this->name<<" Automobile has "<<FuelinTank<<"L of Fuel Left in tank,It has travelled "<<_distance<< " km at a cost of $"<<LitresPerHour*time<<std::endl;
    
    // catch(Err_Status& a){
    //     std::cout<<"Boat Out Of Fuel"<<std::endl;
    //     return Err_Status::Err_OutOfFuel;

    // }
    return Err_Status::Err_Success;

}
Vehicle::Err_Status Boat::AddFuel(double amount){
    double amountAdded=0;
    if(this->FuelinTank+amount>CAPACITY){
        amountAdded=CAPACITY-FuelinTank;
        accumalatedCost+=amountAdded*AMOUNT;
        this->FuelinTank=150.0;
        std::cerr<<this->name<<" Has encountered a fuel overflow the amount added is actually "<<amountAdded<<" L at a cost of $"<<amountAdded*AMOUNT<<std::endl;
        return Err_Status::Err_FuelOverflow;
    }
    this->FuelinTank+=amount;
    amountAdded=FuelinTank-amount;
    accumalatedCost+=amountAdded*AMOUNT;
    std::cout<<this->name<<" Has been added a fuel of  "<<amountAdded<<" L at a cost of "<<amountAdded*AMOUNT<<std::endl;
    return Err_Status::Err_Success;


    
}
double Boat::GetFuel(){
    return this->FuelinTank;

}
double Boat::GetCost(){
    return this->accumalatedCost;
}