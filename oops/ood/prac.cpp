#include<iostream>
#include<bits/stdc++.h>
using namespace std;












































































// class ParkingLot{
//     public:
//     list<ParkingLotFloor> parkingLotFloor;
//     string ParkingLotName;
//     list<Entrance> entrancegate;
//     list<ExitGate> exitgate;
//     bool isParkingSpaceAvail(Vehicle vehicle);
//     bool updateParkingAttendant(ParkingAttendant ParkingAttendant);

// };



// class ParkingLotFloor{
//     public:
//     int floorNo;
//     bool isFull;
//     list<ParkingSpaces> Parkingspaces;
//     ParkingBoard parkingboard;

// };

// class ParkingBoard {
//     public:
//     map<VehicleType , int > ParkingDisplayBoard;
//     int NoofFreeSpotsAvailable;
//     void UpdateFreeSpots(VehicleType  VehicleType,int space);
// };


// class ParkingSpaces{
//     public:
//     int spaceId;
//     bool isFree;
//     double costPerHour;
//     Vehicle vehicle;  //contains details regarding the vehicle present in the parking space

// };

// class Gate{
//     public:
//     int gateId;
//     ParkingAttendant parkingAttendant;
// };



// class Entrance : public Gate{ // INHERIT
//     public:
//     ParkingTicket ParkingTicketIssued(Vehicle Vehicle);
// };
// class ExitGate : public Gate{// INHERIT
//     ParkingTicket ParkingTicketPayment(Vehicle Vehicle, Payment Payment);
// };


// class Payment{
//         public:
//     double amount;
//     int paymentTime;
//     int transactionId;
//     ParkingTicket parkingTicket;
//     PaymentStatus paymentStatus;
// };

// class ParkingAttendant{
//      public:
//     string name;
//     Payment paymentService; //since attendant is responsible for handling the payments
//     bool processVehicleEntry(Vehicle vehicle);
// };


// class ParkingTicket{
//     public:
//     int ticketId;
//     int levelId;
//     int spaceId;
//     int vehicleEntryTime;
//     int vehicleExitTime;
//     VehicleType VehicleType;
//     PaymentStatus parkingStatus;
//     double totalCost;

//     void updateTotalCost();
//     void updateVehicleExitTime(int vehicleExitTime);

// };






// class Vehicle{
//     string LicenseNo;
//     VehicleType vehicleType;
//     PaymentStatus paymentStatus;
// };




// enum VehicleType{Small , Mid , Large , Handicapped };
// enum PaymentMethods{Cash , CreditCard , Upi};
// enum PaymentStatus {Paid, Inactive};




// int main(){

// }

