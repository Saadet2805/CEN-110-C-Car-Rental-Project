#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "structures.h"
#include "design.h"
int numOfCars;
int numOfRes;
int numOfClients;
#include "Layan_Get_Data.h"
#include "saadet.h"
#include "selma.h"
#include "layan.h"
int main()
{
    system("color 0B");
    start();
    //HEADS//
    struct reservation *res=NULL, *resTail=NULL;
    struct client *cus=NULL, *cusTail=NULL;
    struct vehicle *car = NULL, *carTail=NULL;

    //GETTING THE DATA// - layan
    getResFromFile(&res, &resTail);
    getCarsFromFile(&car, &carTail);
    getClientsFromFile(&cus, &cusTail);
    //MENU OPTIONS
    while(1){
    menuDesign();
    int option;
    scanf("%d", &option);
    switch(option){
            //saadet
            case 1:{//display all car info
                option1();
                EasyDisplay(car);
            break;
            }
            //selma
            case 2:{//Display available vehicles currently.
                option2();
                printf ("Available cars are : \n");
                const char* cars = "cars.txt";
                carAvailability(cars);
            break;
            }
            //selma
            case 3:{//Display vehicles that will be available after x days.
                option3();
                printf ("Available cars are : \n");
                const char* cars = "cars.txt";
                displayReservationsAfterXDays(car);
                carAvailability(cars);


            break;
            }
            //saadet
            case 4:{//Create a new reservation.
                option4();
                createReservation(car, &res);
                printReservationsToFile(&res, &resTail);
                printCarsToFile(&car, &carTail);
            break;
            }
            //selma
            case 5:{//add new car
                option5();
                int choice;
                while (1) {
                    printf("1. Add a new car\n");

                    printf("2. Exit\n");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                        addCar(&car);
                    }
                     else if (choice == 2)
                     {
                        printf("You Exited\n");
                        break;
                    } else {
                        printf("Please try again \n");
                    }
                }
            break;
            }
            //saadet
            case 6:{//Search for a vehicle using the license plate number.
                option6();
                searchVehicleByPlateNum(car);
            break;
            }
            //layan
            case 7:{//Sort and display all vehicles according to their daily rental price.
                option7();
                struct vehicle arr[numOfCars];
                getCarsInArray(arr);
                sort_car_by_price(arr);
                //add display function
            break;
            }
            //layan
            case 8:{//Display the top 3 most reserved vehicles.
                option8();
                sort_on_CarCnt(&car);
                show_top_three(car);
            break;
            }
            //selma
            case 9:{//Display all reservations.
                option9();
                const char* reservations = "reservations.txt" ;
                displayAllReservations (reservations);
            break;
            }
            //saadet
            case 10:{//Remove a vehicle.
                option10();
                deleteNode(&car);
                printCarsToFile(&car, &carTail);
            break;
            }
            //layan
            case 11:{//Remove a reservation.
                option11();
                deleteRes(&res);
            break;
            }
            //selma
            case 12:{//client rented a vehicle more than 3 times.
                option12();
                const char* Clients ="Clients.txt"  ;
                printClients(Clients);

            break;
            }
            //layan
            case 13:{//reservations with a total cost exceeding x to a new file.
                option13();
                struct reservation arr[numOfRes];
                GetDataInArray(arr);
                sort_total_price(arr);
                printToNewFile(arr);
            break;
            }
            //saadet
            case 14:{//Modify information for a vehicle using its plate number.
                option14();
                modifyCarInfo(&car);
                printCarsToFile(&car, &carTail);
            break;
            }
            //layan
            case 15:{
                option15();
                struct client arrC[numOfClients];
                getClientsInArray(arrC);
                sortByPhoneNum(arrC);
                binarySearchPhone(arrC);
            }
            case -1:{ break; }  //exiting the loop
            default:{
                printf("ERROR: not an option in the menu, please enter a valid option.");
                break;
            }
        }
        printf("Task Complete!\n");
        printf("------------------------------\n");
        if(option == -1){ break; }//exiting the loop
    }
    ending();
    return 0;
}
