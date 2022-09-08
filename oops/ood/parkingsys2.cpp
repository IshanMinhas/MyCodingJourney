#include<bits/stdc++.h>
using namespace std;

class parkingLot {   //defining the base class
 public:

    list<parkingFloor> parkingFloor; //for the parking floor
    list<entrance> entrance;                // to store the entrance gates
    list<exitgate> exitgate;                         //to store the exits

    /*Address address;*/                           
    string parkingLotName;                  //to store name of parking lot

    bool isParkingSpaceAvailable(vehicle vehicle);
    bool updateParkingAttendant(parkingAttendant parkingAttendant, int gateId);
};

class parkingFloor {
    public:
 int levelid; //what level does the parking floor belong to
 bool isFull; 
 list<parkingSpace> parkingSpaces;
 parkingDisplayBoard parkingDisplayBoard;
};

class gate {
    public:
    int gateId;
    parkingAttendant parkingAttendant;
};

class entrance: public gate{ //entrance inherits gate class
    public:
     parkingTicket getParkingTicket( vehicle vehicle);
};
class exitgate: public gate{ //exit inherits gate class
public:
 parkingTicket payForParking( parkingTicket parkingTicket, paymentType paymentType);
};


class parkingSpace{
    public:
    int spaceId;
    bool isFree;
    double costPerHour;
    vehicle vehicle;  //contains details regarding the vehicle present in the parking space
    parkingSpaceType parkingSpaceType; //to determine what kind of vehicle can be stored in this space

};

class parkingDisplayBoard{
    public:
    map<parkingSpaceType, int> freeSpotsAvailable;
    void updateFreeSpots(parkingSpaceType parkingSpaceType, int spaces );

};

/*class Account{
    public:
    string name;
    string email;
    string password;
    string empid;
    Address address;
};
class Admin : public Account{   //responsible for adding more parking floors or spaces
    public:
    bool addParkingFloor(parkingLot parkingLot, parkingFloor parkingFloor);
     bool addParkingSpace(parkingFloor parkingFloor, parkingSpace parkingSpace);
     bool addParkingDisplayBoard(parkingFloor parkingFloor, parkingDisplayBoard parkingDisplayBoard);
};*/




class parkingAttendant{
    public:
    string name;
    payment paymentService; //since attendant is responsible for handling the payments
    bool processVehicleEntry(vehicle vehicle);
    paymentInfo processPayment(parkingTicket parkingTicket, paymentType paymentType );
};



class vehicle{
    public:
    string licenseNumber;
    vehicleType vehicleType;
    parkingTicket parkingTicket;
    paymentInfo paymentInfo;
};





class parkingTicket{
    public:
    int ticketId;
    int levelId;
    int spaceId;
    int vehicleEntryTime;
    int vehicleExitTime;
    parkingSpaceType parkingSpaceType;
    parkingTicketStatus parkingTicketStatus;
    double totalCost;

    void updateTotalCost();
    void updateVehicleExitTime(int vehicleExitTime);

};

// enum -> spl data type which contains constant datatypes for var
enum paymentType{CASH, CREDIT, DEBIT, UPI};


enum parkingSpaceType{BIKE_PARKING, CAR_PARKING, TRUCK_PARKING};


class payment{
public:
 paymentInfo makePayment(parkingTicket parkingTicket, paymentType paymentType);
};



class paymentInfo{
    public:
double amount;
int paymentTime;
int transactionId;
parkingTicket parkingTicket;
paymentStatus paymentStatus;
};


enum vehicleType{BIKE, CAR, TRUCK};


enum parkingTicketStatus{PAID, ACTIVE};


enum paymentStatus{UNPAID, PENDING, COMPLETED, DECLINED, CANCELLED, REFUNDED};


int main(){

}