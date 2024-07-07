#ifndef SAADET_H_INCLUDED
#define SAADET_H_INCLUDED
void searchVehicleByPlateNum(struct vehicle *car)
{
    char plateNumber[8];
    printf("Enter the plate number you are searching for: \n");
    scanf("%s", plateNumber);

    while(car!=NULL) //using car, bc its content is not being changed in this function
    {
            if (strcmp(car->plateNum, plateNumber) == 0) // if the plate number you are searching for is the same as the current node's plate number return the node
            {
                printf("The car with the plate number you are searching for is found.\nHere are its specifications:\n");
                printf("\
Plate number: %s\n\
Year: %d\n\
Model: %s\n\
Fuel type: %s\n\
Fuel consumption: %d\n\
Number of seats: %d\n\
Daily price: %lf\n\
Number of times rented: %d\n\
Availability: %d\n",
                car->plateNum, car->year, car->model, car->fuelType, car->consumption, car->seats,
                car->dailyPrice, car->CarRentalCnt, car->availability);
                return;
            }
        car=car->carNext;
    }
    printf("the car with the plate number %s was not found\n", plateNumber);
}

void modifyCarInfo(struct vehicle **car)
{
    struct vehicle *curr;
    char plateNumber[8];
    printf("Enter the plate number you are searching for: ");
    scanf("%s", plateNumber);

    curr=*car;
    while(curr!=NULL)
    {
            if (strcmp(curr->plateNum, plateNumber) == 0) // if the plate number you are searching for is the same as the current node's plate number return the node
            {
                printf("Choose what to modify (Type '0' if you are done modifying):\n");
                printf("\
1-Plate number\n\
2-Year\n\
3-Model\n\
4-Fuel Type\n\
5-Consumption\n\
6-Number of seats\n\
7-Daily Price\n\
8-Change all\n\
choice: ");

                int option;
                scanf("%d", &option);
                switch(option)
                {
                case 1:
                {
                    scanf("%s", curr->plateNum);
                    break;
                }
                case 2:
                {
                    scanf("%d",&curr->year);
                    break;
                }
                case 3:
                {
                    scanf("%s", curr->model);
                    break;
                }
                case 4:
                {
                    scanf("%s", curr->fuelType);
                    break;
                }
                case 5:
                {
                    scanf("%d", &curr->consumption);
                    break;
                }
                case 6:
                {
                    scanf("%d", &curr->seats);
                    break;
                }
                case 7:
                {
                    scanf("%lf", &curr->dailyPrice);
                    break;
                }
                case 8:
                {
                    scanf("%s %d %s %s %d %d %lf %d %d", curr->plateNum, &curr->year, curr->model, curr->fuelType, &curr->consumption, &curr->seats, &curr->dailyPrice, &curr->CarRentalCnt, &curr->availability);
                    break;
                }
                case 0:
                    break;
                }
                return;
            }
        curr=curr->carNext;
    }
}

void EasyDisplay(struct vehicle *car) // we can pass the car of the list with a single pointer as we will not change the content of it
{
    int cnt=1;
    while(car!=NULL) // while the list has not come to an end (when the node does not point to null), print the information
    {
            printf("Vehicle %d information: ", cnt);
            printf("\nPlate Number: %s\n", car->plateNum);
            printf("Year: %d\n", car->year);
            printf("Model: %s\n", car->model);
            printf("Fuel Type: %s\n", car->fuelType);
            printf("Consumption: %d\n", car->consumption);
            printf("Seats: %d\n", car->seats);
            printf("Daily Price: %.2lf\n", car->dailyPrice);
            printf("Car Rental Count: %d\n", car->CarRentalCnt);
            printf("Availability: %d\n", car->availability);
            printf("\n");
            printf("------------------------\n");
            cnt++;
        car = car->carNext;
    }
}

void createReservation(struct vehicle *car, struct reservation **res) //add reservation at the end of the list
{
    double price; // this price is the price that the car actually has
    char plateNumber[8];
    struct reservation *prev=NULL, *curr=NULL, *newRes=NULL; // create pointers for the linked lists

    printf("Enter the plate number of the car the client wants to rent:\n");
    scanf("%s", plateNumber);

    while(car!=NULL) //using car, bc its content is not being changed in this function
    {
            if (strcmp(car->plateNum, plateNumber) == 0) // if the plate number you are searching for is the same as the current node's plate number return the node
            {
                if(car->availability == 0)
                {
                    car->availability = 1;
                    //create new node
                    newRes = (struct reservation*) malloc(sizeof(struct reservation));
                    printf ("\nEnter the reservation ID: \n");

                    //Enter data for each section of the structure
                    scanf ("%d", &newRes->reservationID);
                    printf("Enter the date: ");
                    for(int i=0;i<3;i++)
                    {
                        scanf("%d", &newRes->date[i]);
                    }
                    printf("\nEnter the client ID: \n");
                    scanf("%d", &newRes->clientID);
                    strcpy(newRes->carID,plateNumber);
                    //calculate the price
                    printf("Enter the price of the car:");
                    scanf("%lf", &price);
                    printf("\nEnter number of days the car is rented for: \n");
                    scanf("%d", &newRes->numOfDays);
                    if(newRes->numOfDays == 7)
                    {
                        newRes->totalPrice=price*0.9;
                    }
                    else if(newRes->numOfDays == 14)
                    {
                        newRes->totalPrice=price*0.85;
                    }
                    else if(newRes->numOfDays == 28 && newRes->numOfDays == 29 && newRes->numOfDays == 30 && newRes->numOfDays == 31)
                    {
                        newRes->totalPrice=price*0.8;
                    }
                    newRes->resNext=NULL;

                    //add node to the linked list
                    curr=*res;

                    if(*res==NULL)
                    {
                        *res=newRes;
                    }
                    while (curr != NULL)
                    {
                    prev = curr;
                    curr = curr->resNext;
                    }
                    if(curr==NULL)
                    {
                        prev->resNext=newRes;
                        newRes->resNext=NULL;
                    }
                    //increment number of reservations
                    numOfRes++;
                    return;
                }
                else
                {
                    printf("The car you are looking for is not available at the moment.");
                    return;
                }
            }
        car=car->carNext;
    }
    printf("the car does not exist");

}

void deleteNode(struct vehicle **car)
{
    printf("Delete vehicle info with plate number: ");
    char plateNum[8];
    scanf("%s", plateNum);
    struct vehicle *curr = *car, *prev = NULL; // we use the pointer curr to not modify the car pointer

    if(curr == NULL)
    {
        printf("The list is empty.");
        return;
    }

    while (curr != NULL && strcmp(curr->plateNum, plateNum) != 0) //While not at the end of the list and the platenumber is not found, move on to the next node
    {
        prev = curr;
        curr = curr->carNext;
    }

    if (curr == NULL)
    {
        printf("Node with plate number '%s' not found.\n", plateNum);
        return;
    }

    if (prev == NULL)
    {
        *car = curr->carNext;
    }
    // set the next pointer of the prev node to the current's next pointer
    else
    {
        prev->carNext = curr->carNext;
    }
    //free the node
    free(curr);

    //decrement number of cars
    numOfCars--;
}

void printReservationsToFile(struct reservation **res, struct reservation **resTail)
{
    FILE *file;
    file = fopen("reservations.txt", "w"); //overwrite the file to rewrite the linked list inside the file
    if(file == NULL)
    {
        printf("Error: Could not open the file reservations.txt");
        return ;
    }

    fprintf(file, "%d\n", numOfRes);
    if(numOfRes == 0)
    {
        printf("You have no cars in the system.");
        return;
    }

    struct reservation *newRes;
    newRes=*res;
    for(int i=0; i<numOfRes; i++)
    {
        //reservation id
        fprintf(file, "%d ", newRes->reservationID);
        //date
        for(int j=0; j<3; j++)
        {
            fprintf(file, "%5d ", newRes->date[j]);
        }
        //client id, number of days, car id, total price
        fprintf(file, "%5d %5d %5s %5lf ", newRes->clientID, newRes->numOfDays, newRes->carID, newRes->totalPrice);
        fprintf(file, "\n");
        newRes = newRes->resNext;
    }
}

void printCarsToFile(struct vehicle **car, struct vehicle **carTail)
{
    FILE *file;
    file = fopen("cars.txt", "w");
    if(file == NULL)
    {
        printf("Error: Could not open the file cars.txt");
        return ;
    }
    fprintf(file, "%d", numOfCars);
    fprintf(file, "\n");
    if(numOfCars == 0)
    {
        printf("you have no cars in the system");
        return;
    }
    struct vehicle *newCar;
    newCar=*car;
    for(int i=0; i<numOfCars; i++)
    {
        fprintf(file, "%s %5d %5s ", newCar->plateNum, newCar->year, newCar->model);
        fprintf(file, "%5s %5d %5d ", newCar->fuelType, newCar->consumption, newCar->seats);
        fprintf(file, "%5lf %5d %5d", newCar->dailyPrice, newCar->CarRentalCnt, newCar->availability);
        fprintf(file, "\n");
        newCar = newCar->carNext;
    }
}

void printClientsToFile(struct client **cus, struct client **cusTail)
{
    FILE *file;
    file = fopen("clients.txt", "w");
    if(file == NULL)
    {
        printf("Error: Could not open the file clients.txt");
        return ;
    }

    fprintf(file, "%d ", numOfClients);
    fprintf(file, "\n");
    if(numOfClients == 0)
    {
        printf("You have no clients in the system.");
        return;
    }
    struct client *newCus;
    newCus=*cus;
    for(int i=0; i<numOfClients; i++)
    {
        fprintf(file, "%d %5s %5s", newCus->clientID, newCus->name, newCus->surname);
        fprintf(file, "%5s %5d %0.lf %5d", newCus->passportID, newCus->state, newCus->phone, newCus->ClientRentalCnt);
        fprintf(file, "\n");
        newCus = newCus->clientNext;
    }
}

#endif // SAADET_H_INCLUDED
