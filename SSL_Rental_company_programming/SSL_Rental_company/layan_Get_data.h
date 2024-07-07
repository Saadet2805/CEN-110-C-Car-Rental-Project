#ifndef LAYAN_GET_DATA_H_INCLUDED
#define LAYAN_GET_DATA_H_INCLUDED

//get data from file
void getResFromFile(struct reservation **res, struct reservation **resTail){
//to get the information from the reservation file
    FILE *file;
    file = fopen("reservations.txt", "r");
    if(file == NULL){
        printf("Error: Could Not Open the file reservations.txt");
        return ;
    }
    fscanf(file, "%d", &numOfRes);
    if(numOfRes == 0){
        printf("you currently have no previous reservations");
        return;
    }
    struct reservation *newRes;
    for(int i=0; i<numOfRes; i++){
        newRes = (struct reservation *)malloc(sizeof(struct reservation));
        //reservation id
        fscanf(file, "%d", &newRes->reservationID);
        //date
        for(int j=0; j<3; j++){
            fscanf(file, "%d", &newRes->date[j]);
        }
        //client id, number of days, car id, total price
        fscanf(file, "%d%d%s%lf", &newRes->clientID, &newRes->numOfDays, newRes->carID, &newRes->totalPrice);
        newRes->resNext = NULL;
        if(*res == NULL){
            *resTail = newRes;
            *res = newRes;
        }
        else{
            (*resTail)->resNext = newRes;
            *resTail = newRes;
        }
    }
}

void getCarsFromFile(struct vehicle **car, struct vehicle **carTail){
    FILE *file;
    file = fopen("cars.txt", "r");
    if(file == NULL){
        printf("Error: Could Not Open the file cars.txt");
        return ;
    }
    fscanf(file, "%d", &numOfCars);
    if(numOfCars == 0){
        printf("you have no cars in the system");
        return;
    }
    struct vehicle *newCar;
    for(int i=0; i<numOfCars; i++){
        newCar = (struct vehicle *)malloc(sizeof(struct vehicle));
        fscanf(file, "%s%d%s", newCar->plateNum, &newCar->year, newCar->model);
        fscanf(file, "%s%d%d", newCar->fuelType, &newCar->consumption, &newCar->seats);
        fscanf(file, "%lf%d%d", &newCar->dailyPrice, &newCar->CarRentalCnt, &newCar->availability);
        if(*car == NULL){
            *carTail = newCar;
            *car = newCar;
        }
        else{
            (*carTail)->carNext = newCar;
            *carTail = newCar;
        }
    }
}

void getClientsFromFile(struct client **cus, struct client **cusTail){
//to get the information from the clients file
    FILE *file;
    file = fopen("clients.txt", "r");
    if(file == NULL){
        printf("Error: Could Not Open the file clients.txt");
        return ;
    }
    fscanf(file, "%d", &numOfClients);
    if(numOfClients == 0){
        printf("you have no clients in the system");
        return;
    }
    struct client *newCus;
    for(int i=0; i<numOfClients; i++){
        newCus = (struct client *)malloc(sizeof(struct client));
        fscanf(file, "%d%s%s", &newCus->clientID, newCus->name, newCus->surname);
        fscanf(file, "%s%d%lf%d", newCus->passportID, &newCus->state, &newCus->phone, &newCus->ClientRentalCnt);
        if(*cus == NULL){
            *cusTail = newCus;
            *cus = newCus;
        }
        else{
            (*cusTail)->clientNext = newCus;
            *cusTail = newCus;
        }
    }
}
void getCarsInArray(struct vehicle newCar[]){
    FILE *file;
    file = fopen("cars.txt", "r");
    if(file == NULL){
        printf("Error: Could Not Open the file cars.txt");
        return;
    }
    fscanf(file, "%d", &numOfCars);
    if(numOfCars == 0){
        printf("you have no cars in the system");
        return;
    }
    for(int i=0; i<numOfCars; i++){
        fscanf(file, "%s%d%s", newCar[i].plateNum, &newCar[i].year, newCar[i].model);
        fscanf(file, "%s%d%d", newCar[i].fuelType, &newCar[i].consumption, &newCar[i].seats);
        fscanf(file, "%lf%d%d", &newCar[i].dailyPrice, &newCar[i].CarRentalCnt, &newCar[i].availability);
    }
}
#endif // LAYAN_GET_DATA_H_INCLUDED
