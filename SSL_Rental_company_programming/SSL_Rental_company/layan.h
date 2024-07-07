#ifndef LAYAN_H_INCLUDED
#define LAYAN_H_INCLUDED




// show Top 3
void swapping(struct vehicle **curr, struct vehicle **prev){
    int tempAvailability, tempCarRentalCnt, tempConsumption, tempSeats, tempYear;
    double tempDailyPrice;
    char tempFuelType[30]; char tempModel[30]; char tempPlateNum[8];
    //values of temp
    tempAvailability = (*curr)->availability;//int
    tempCarRentalCnt = (*curr)->CarRentalCnt;//int
    tempConsumption = (*curr)->consumption;//int
    tempDailyPrice = (*curr)->dailyPrice;//double
    strcpy(tempFuelType, (*curr)->fuelType);//string
    strcpy(tempModel, (*curr)->model);//string
    strcpy(tempPlateNum, (*curr)->plateNum);//string
    tempSeats = (*curr)->seats;//int
    tempYear = (*curr)->year;//int
    //changing the curr
    (*curr)->availability = (*prev)->availability;
    (*curr)->CarRentalCnt = (*prev)->CarRentalCnt;
    (*curr)->consumption = (*prev)->consumption;
    (*curr)->dailyPrice = (*prev)->dailyPrice;
    strcpy((*curr)->fuelType, (*prev)->fuelType);
    strcpy((*curr)->model, (*prev)->model);
    strcpy((*curr)->plateNum, (*prev)->plateNum);
    (*curr)->seats = (*prev)->seats;
    (*curr)->year = (*prev)->year;
    //changing the prev
    (*prev)->availability = tempAvailability;
    (*prev)->CarRentalCnt = tempCarRentalCnt;
    (*prev)->consumption = tempConsumption;
    (*prev)->dailyPrice = tempDailyPrice;
    strcpy((*prev)->fuelType, tempFuelType);
    strcpy((*prev)->model, tempModel);
    strcpy((*prev)->plateNum, tempPlateNum);
    (*prev)->seats = tempSeats;
    (*prev)->year = tempYear;
}

void sort_on_CarCnt(struct vehicle **car){
    struct vehicle *curr, *prev;
    curr = *car;
    //sorting the carRentalCnt:
    //from smallest to largest
    while(curr != NULL){
        prev = curr->carNext;
        while(prev != NULL){
            if(prev->CarRentalCnt > curr->CarRentalCnt){
                swapping(&curr, &prev);
            }
            prev = prev->carNext;
        }
        curr = curr->carNext;
    }
}

void show_top_three(struct vehicle *car){
    struct vehicle *curr;
    curr = car;
//first
    printf("\
*****first*****: \n\
model: %s\n\
licence plate: %s\n\
price: %lf\n\
rental count: %d\n",
    curr->model, curr->plateNum, curr->dailyPrice, curr->CarRentalCnt);
    curr = curr->carNext;
//second
    printf("\
*****second*****: \n\
model: %s\n\
licence plate: %s\n\
price: %lf\n\
rental count: %d\n",
    curr->model, curr->plateNum, curr->dailyPrice, curr->CarRentalCnt);
    curr = curr->carNext;
//third
    printf("\
*****third*****: \n\
model: %s\n\
licence plate: %s\n\
price: %lf\n\
rental count: %d\n",
    curr->model, curr->plateNum, curr->dailyPrice, curr->CarRentalCnt);
    curr = curr->carNext;
}

//deleting a reservation
void deleteRes(struct reservation **res){
    printf("reservation ID to delete: ");
    int resID;
    scanf("%d", &resID);
    struct reservation *curr, *prev ;
    curr = *res;
    prev = NULL;
    if(curr == NULL){
        printf("there are no reservations\n");
        return;
    }

    while (curr != NULL){
        if(resID == curr->reservationID)
            break;
        prev = curr;
        curr = curr->resNext;
    }
    //ID not found
    if (curr == NULL){
        printf("reservation with ID %d not found.\n", resID);
        return;
    }
    //checking if its the first element
    else if (prev == NULL) *res = (*res)->resNext;
    else prev->resNext = curr->resNext;
    //free the node
    free(curr);
    //decreasing the number of reservations by 1

    numOfRes--;

}

//search for client by phone number
void getClientsInArray(struct client arrC[]){
//getting clients into an array
    FILE *cFile;
    cFile = fopen("clients.txt", "r");
    int x;
    fscanf(cFile, "%d", &x);
    for(int i=0; i<x; i++){
        fscanf(cFile, "%s%s%d%s%d%lf%d",
            arrC[i].name, arrC[i].surname, &arrC[i].clientID, arrC[i].passportID,
             &arrC[i].state, &arrC[i].phone, &arrC[i].ClientRentalCnt);
    }
}


void binarySearchPhone(struct client arrC[])
{
    printf("\nenter the phone number you want to find: ");
    double x;
    scanf("%lf", &x);
    int minX = 0;
    int maxX = numOfClients - 1;
    while (minX <= maxX )
    {
        int mid = (minX + maxX) / 2;
        if (x == arrC[mid].phone){
            printf("\nname: %s\nsurname: %s \nID: %d \nphone: %0.lf\n",
                   arrC[mid].name, arrC[mid].surname, arrC[mid].clientID, arrC[mid].phone);
            return;
        }
        else if (x < arrC[mid].phone)
            maxX = mid - 1;
        else
            minX = mid + 1;

    }
    printf("client with the phone number you have selected does not exist\n please check that you have entered it correctly\n");
    return ;
}

void sortByPhoneNum(struct client arrC[]){
    int minC;
    for(int i=0; i<numOfClients-1; i++){
        minC = i;
        for(int j=i+1; j<numOfClients; j++){
            if(arrC[minC].phone > arrC[j].phone){
                minC = j;
            }
        }
        if(minC != i){
            struct client temp;
            temp = arrC[minC];
            arrC[minC] = arrC[i];
            arrC[i] = temp;
        }
    }
}

void GetClientByPhone(){
    struct client arrC[numOfClients];
    getClientsInArray(arrC);
    sortByPhoneNum(arrC);
    binarySearchPhone(arrC);
}

//sorting cars by their daily price
void sort_car_by_price(struct vehicle arrC[]){
    int minC;
    for(int i=0; i<numOfCars-1; i++){
        minC = i;
        for(int j=i+1; j<numOfCars; j++){
            if(arrC[minC].dailyPrice > arrC[j].dailyPrice){
                minC = j;
            }
        }
        if(minC != i){
            struct vehicle temp;
            temp = arrC[minC];
            arrC[minC] = arrC[i];
            arrC[i] = temp;
        }
    }
    for(int i=0; i<numOfCars; i++){
        printf("Vehicle %d information: ", i);
        printf("\nPlate Number: %s\n", arrC[i].plateNum);
        printf("Year: %d\n", arrC[i].year);
        printf("Model: %s\n", arrC[i].model);
        printf("Fuel Type: %s\n", arrC[i].fuelType);
        printf("Consumption: %d\n", arrC[i].consumption);
        printf("Seats: %d\n", arrC[i].seats);
        printf("Daily Price: %.2lf\n", arrC[i].dailyPrice);
        printf("Car Rental Count: %d\n", arrC[i].CarRentalCnt);
        printf("Availability: %d\n", arrC[i].availability);
        printf("\n");
        printf("------------------------\n");
    }
}

//reservations exceeding x
void GetDataInArray(struct reservation arr[]){
    FILE *file;
    file = fopen("reservations.txt", "r");
    if(file == NULL){
        printf("Error: Could Not Open the file reservations.txt");
        return ;
    }
    fscanf(file, "%d", &numOfRes);
    for(int i=0; i<numOfRes; i++){
        //reservation id
        fscanf(file, "%d", &arr[i].reservationID);
        //date
        for(int j=0; j<3; j++){
            fscanf(file, "%d", &arr[i].date[j]);
        }
        //client id, number of days, car id, total price
        fscanf(file, "%d%d%s%lf", &arr[i].clientID, &arr[i].numOfDays, arr[i].carID, &arr[i].totalPrice);
    }
}

void sort_total_price(struct reservation arr[]){
//sorting the data based on the total price
    int minI;
    for(int i=0; i<numOfRes; i++){
        minI = i;
        for(int j=i+1; j<numOfRes; j++){
            if(arr[j].totalPrice < arr[minI].totalPrice){
                minI =j;
            }
        }
        //swapping
        struct reservation temp;
        temp = arr[i];
        arr[i] = arr[minI];
        arr[minI] = temp;

    }
}

void printToNewFile(struct reservation arr[]){
    double x;
    printf("enter the minimum total price of the reservations that will be stored in the new file: ");
    scanf("%lf", &x);
    int index = -1;
    //creating a new file
    FILE *newFile;
    newFile = fopen("exceeding_x.txt", "w");
    GetDataInArray(arr);
    sort_total_price(arr);
    for(int i=0; i<numOfRes; i++){
        if(arr[i].totalPrice >= x){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("there are no reservations exceeding the amount you have requested\n");
        fclose(newFile);
        return;
    }
    for(int i=index; i<numOfRes; i++){
        //reservation id
        fprintf(newFile, "%d ", arr[i].reservationID);
        //date
        for(int j=0; j<3; j++){
            fprintf(newFile, "%d ", arr[i].date[j]);
        }
        //client id, number of days, car id, total price
        fprintf(newFile, "%d %d %s %lf \n", arr[i].clientID, arr[i].numOfDays, arr[i].carID, arr[i].totalPrice);
    }
}




#endif // LAYAN_H_INCLUDED
