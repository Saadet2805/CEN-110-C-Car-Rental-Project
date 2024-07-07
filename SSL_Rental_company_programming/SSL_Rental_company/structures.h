#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

struct vehicle{
    char plateNum[8];
    int year;
    char model[30];
    char fuelType[30];
    int consumption;
    int seats;
    double dailyPrice;
    int CarRentalCnt;
    int availability ;
    struct vehicle *carNext;
}vehicle;

struct reservation{
    int reservationID;
    int date[3];
    int clientID;
    int numOfDays;
    char carID[8];
    double totalPrice;
    struct reservation *resNext;
};

struct client{
    char name[20];
    char surname[20];
    int clientID;
    char passportID[6];
    int  state;
    double phone;
    int ClientRentalCnt;
   struct client *clientNext;
};


#endif // STRUCTURES_H_INCLUDED
