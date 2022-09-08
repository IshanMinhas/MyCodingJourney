#include <bits/stdc++.h>
using namespace std;
enum PaymentType;
enum ParkingSpaceType;
enum VehicleType;
enum ParkingTicketStatus;
class Address;
class Vehicle;
class Gate;
class EntryGate;
class ExitGate;
class Account;
class Admin;
class ParkingTicket;
class ParkingAttendant;
class ParkingSpace;
class ParkingFLoor;
class ParkingLot;


class ParkingLot {
    vector <ParkingFloor> parkingFloors;
    Address parkingLotAddress;
    string parkingLotName;
    vector<EntryGate> entryGates;
    vector<ExitGate> exitGates;

    bool isParkingSpaceAvailableForVehicle(Vehicle vehicle);
    bool updateAttendant(ParkingAttendant attendant, int gateId);
};

class ParkingSpace{
    int spaceId;
    bool isFree;
    double costPerHour;
    Vehicle vehicle;
    ParkingSpaceType parkingSpaceType;
 
};



class ParkingFloor{
    int levelId;
    vector<ParkingSpace> parkingSpaces;
};


class Address{
    string streetNumber;
    string city;
    string state;
    int pincode;
};

class Vehicle{
    int vehicleNo;
    VehicleType vehicleType;
    ParkingTicket parkingTicket;
};


class Gate{
    public:
    int gateNo;
};


class EntryGate : public Gate {
    bool assignParkingSpaceToVehicle(Vehicle vehicle);
};

class ExitGate : public Gate {
    // Receipt generateReceipt(Vehicle vehicle);
    bool deassignParkingSpaceToVehicle(Vehicle vehicle);
};


class Account{
    public:
    string name;
    string email;
    string password;
    int empId;
};

class Admin : public Account{
    public:
    bool addParkingFloor(ParkingLot parkingLot, ParkingFloor parkingFloor);
    bool addParkingSpace(ParkingFloor parkingFloor, ParkingSpace parkingSpace);
};

class ParkingAttendant : public Account{
    public:
    bool add;
};  

class ParkingTicket{
    int ticketId;
    int spaceId;
    int levelId;
    string vehicleEntryDateTime;
    string vehicleExitDateTime;
    ParkingSpaceType ParkingSpaceType;
    double totalCost;
    ParkingTicketStatus parkingTicketStatus;
    
    void updateTotalCost();
    void updateVehicleExitTime(string exitTime);
};

enum VehicleType{
    BIKE, CAR, TRUCK
};

enum PaymentType{
    CASH, CREDIT_CARD, DEBIT_CARD, UPI
};

enum ParkingSpaceType{
    BIKE_PARKING, CAR_PARKING, TRUCK_PARKING
};

enum ParkingTicketStatus{
    PAID, UNPAID
};

int main(){

    return 0;
}