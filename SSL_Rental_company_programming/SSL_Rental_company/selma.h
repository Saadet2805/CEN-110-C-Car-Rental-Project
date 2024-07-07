#ifndef SELMA_H_INCLUDED
#define SELMA_H_INCLUDED

void carAvailability (const char* cars  )
{
    FILE* file= fopen(cars, "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }
    struct vehicle car;
    int x;
    fscanf(file, "%d", &x);
    for(int i=0; i<numOfCars; i++)
    {
        fscanf (file, "%s %d %s %s %d %d %lf %d %d ", car.plateNum, &car.year, car.model, car.fuelType, &car.consumption, &car.seats, &car.dailyPrice, &car.CarRentalCnt, &car.availability);
        if (car.availability == 0)
        {
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
                car.plateNum, car.year, car.model, car.fuelType, car.consumption, car.seats,
                car.dailyPrice, car.CarRentalCnt, car.availability);
            printf ("-----------------------\n");
        }
    }
    fclose(file);
}

void displayAllReservations ( const char* reservations)
{

    FILE* file = fopen("reservations.txt", "r");
    if (file == NULL)
    {
        printf ("Error");
        return ;
    }

    char carID[10];
    int date [3];
    int reservationID, clientID, days;
    double totalPrice;
    int x;
    fscanf(file, "%d", &x);
    for(int i=0; i<x; i++)
    {
        fscanf(file, "%d%d%d%d%d%d%s%lf", &reservationID, &date[0], &date[1], &date[2], &clientID, &days, carID, &totalPrice);
        printf ("Car ID : %s\n", carID);
        printf ("Reservation ID : %d\n", reservationID);
        printf ("Date it was reserved : %d %d %d\n", date[0], date[1], date[2]);
        printf ("Client ID: %d\n",clientID );
        printf ("Number of times it was Reserved: %d\n", days);
        printf ("Total Price : %lf\n", totalPrice);
        printf ("\n\n");
    }

    fclose(file);
}

struct vehicle* createCar()
{
    struct vehicle* newCar = (struct vehicle*)malloc(sizeof(struct vehicle));
    newCar->carNext = NULL;
    return newCar;
}
void saveCarsToFile(struct vehicle* head)
{
    FILE* file = fopen("cars.txt", "w");
    if (file == NULL)
    {
        printf("No File Found \n");
        return;
    }
    struct vehicle* temp = head;
    fprintf(file, "%d\n", numOfCars);
    while (temp != NULL)
    {
        // plateNum year model fuel consum seats price availability
        fprintf(file, "%5s  %5d  %5s  %5s  %5d  %5d  %5.2lf  %5d\n",
                temp->plateNum, temp->year, temp->model, temp->fuelType, temp->consumption,
                temp->seats, temp->dailyPrice, temp->availability);
        temp = temp->carNext;
    }
    fclose(file);
}

void addCar(struct vehicle** head)
{
    struct vehicle* newCar = createCar();
    printf("Enter plate number: ");
    scanf("%s", newCar->plateNum);
    printf("Enter year: ");
    scanf("%d", &newCar->year);
    printf("Enter model: ");
    scanf(" %s", newCar->model);
    printf("Enter fuel type: ");
    scanf("%s", newCar->fuelType);
    printf("Enter consumption: ");
    scanf("%d", &newCar->consumption);
    printf("Enter number of seats: ");
    scanf("%d", &newCar->seats);
    printf("Enter daily rental price: ");
    scanf("%lf", &newCar->dailyPrice);
    printf("Enter availability (1 or 0): ");
    scanf("%d", &newCar->availability);
    if (*head == NULL)
    {
        *head = newCar;
    }
    else
    {
        struct vehicle* temp = *head;
        while (temp->carNext != NULL)
        {
            temp = temp->carNext;
        }
        temp->carNext = newCar;
    }
    numOfCars++;
    saveCarsToFile(*head);
    printf("Car added \n");
}

void printClients (const char* Clients)
{
    FILE* file = fopen (Clients, "r");
    int found =0;
    if (file==NULL)
    {
        printf ("Error");
        return ;
    }
    int x;
    fscanf(file, "%d", &x);
    struct client clients ;
    while (fscanf (file, "%s %s %d %s %d %lf %d", clients.name, clients.surname, &clients.clientID, clients.passportID, &clients.state,&clients.phone, &clients.ClientRentalCnt)==7)
    {
        if (clients.ClientRentalCnt > 3)
        {
            found =1;
            printf("-----------------\n");
            printf ("name: %s\nsurname: %s\npassport ID: %s \n", clients.name, clients.surname, clients.passportID);
        }
    }
    fclose (file);
    if(found == 0)
    {
        printf("there are currently no customers who have rented more than 5 vehicles\n");
    }
}



void displayReservationsAfterXDays(struct vehicle *car)
{
    struct vehicle *reset = car;
    char plateNumber[8];
    FILE* file = fopen("reservations.txt", "r");
    if (file == NULL)
    {
        printf("Error \n");
        return;
    }

    struct reservation Reservation;
    int currentDate[3];
    int x;
    int cnt = 0;
    printf("Enter current date (day month year): ");
    scanf("%d %d %d", &currentDate[0], &currentDate[1], &currentDate[2]);
    printf("Enter number of days: ");
    scanf("%d", &x);

    printf("\nReservations that will be available after %d days:\n", x);
    int ABC;
    fscanf(file, "%d", &ABC);
    while (fscanf(file, "%d %d %d %d %d %d %s %lf",
                  &Reservation.reservationID, &Reservation.date[0], &Reservation.date[1],
                  &Reservation.date[2], &Reservation.clientID, &Reservation.numOfDays,
                  Reservation.carID, &Reservation.totalPrice) == 8)
    {

        if (Reservation.date[2] == currentDate[2] && Reservation.date[1] >= currentDate[1])
        {
            int reservationDay = Reservation.date[0] + Reservation.numOfDays;
            int targetDay = currentDate[0] + x;

            if (reservationDay <= targetDay)
            {
                cnt++;
                strcpy(plateNumber, Reservation.carID);
                car = reset;
                while(car!=NULL) //using car, bc its content is not being changed in this function
                {
                        if (strcmp(car->plateNum, plateNumber) == 0) // if the plate number you are searching for is the same as the current node's plate number return the node
                        {
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
                                                printf("------------------\n");

                        }
                    car=car->carNext;
                }
            }
        }
    }
    if (cnt == 0)
    {
        printf("No reservations available after %d days.\n", x);
    }

    fclose(file);
}





#endif // SELMA_H_INCLUDED
