#include<iostream>
#include<bits/stdc++.h>
using namespace std;
enum VehicleType{
    CAR , TRUCK , BIKE, HANDICAPPED 
};

enum ParkingSpotType{
    HANDICAPPEDD , SMALL , LARGE
};
enum Account{
    ACTIVE , BLOCKED
};

class Attendee{
    void ProcessTicket(){}
    void HandlePaymemts(){}

};
class AccountofCustomer{
    int id;
    int password;
    int visitsinaweek;
    string name;


};
class Admin{
    public:
    void addFloor(){}
    void addParkingSpots(){}
    void createAccountforNewCustomer(){}
    void setFees(){}
    void EntrancePanel(){

    }   
    void ExitPanel(){}
};  


class ParkingSpot{
    bool isFree;
    string type;
    int ParkingspotNo;
    Vehicle vehicle;

    public: 
    ParkingSpot(string type){
        this->type = type;
    }
    void removeSpot(Vehicle vehicle){
        this->vehicle = vehicle;
        isFree = true;
    }
    void AssignSpot(Vehicle vehicle){
        this->vehicle = 0;
        isFree = false;
    }



};
 
class Vehicle{
    string LicenseNo;

  public:
   void assignTicket(ParkingTicket ticket) {
    this.ticket = ticket;
  }
};
class ParkingTicket(){

};





class Handicapped : ParkingSpot{
    public:
    Handicapped(){

    }
};

class LargeVehicle : ParkingSpot{ 
    public:
    LargeVehicle(){

    }
};
class smallVehicle : ParkingSpot{
    public:
    smallVehicle(){

    }
};


















int main(){

}