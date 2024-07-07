#ifndef DESIGN_H_INCLUDED
#define DESIGN_H_INCLUDED
void start(){
    printf("\n\t***************************************************************************");
    printf("\n\t************                                                   ************");
    printf("\n\t************                                                   ************");
    printf("\n\t************                                                   ************");
    printf("\n\t************           welcome to SSL Rental Company           ************");
    printf("\n\t************                                                   ************");
    printf("\n\t************                                                   ************");
    printf("\n\t************                                                   ************");
    printf("\n\t***************************************************************************");
}

void menuDesign(){
printf("\n\t***************************************************************************");
printf("\n\t**************      Enter the task you want to perform      ***************");
printf("\n\t***************************************************************************\n");
printf("\
1. Display all vehicle information.\n\
2. Display available vehicles currently.\n\
3. Display vehicles that will be available after x days.\n\
4. Create a new reservation.\n\
5. Add a new vehicle.\n\
6. Search for a vehicle using the license plate number.\n\
7. Sort and display all vehicles according to their daily rental price.\n\
8. Display the top 3 most reserved vehicles.\n\
9. Display all reservations.\n\
10. Remove a vehicle.\n\
11. Cancel a reservation.\n\
12. Display clients who have rented a vehicle more than 3 times.\n\
13. Save all reservations with a total cost exceeding x to a new file.\n\
14. Modify information for a vehicle using its plate number.\n\
15. Search for a client by phone number.\n\
enter '-1' to exit the menu\n");
printf("choice: ");
}
void ending(){
    printf("\n\t***************************************************************************");
    printf("\n\t***************************************************************************");
    printf("\n\t************      thank you for using SSL Rental Company       ************");
    printf("\n\t************                                                   ************");
    printf("\n\t************         hope to see you again next time           ************");
    printf("\n\t************                                                   ************");
    printf("\n\t***************************************************************************");
    printf("\n\t***************************************************************************");
}
void option1(){
printf("\n\
******************************************************\n\
***********      you have selected (1)     ***********\n\
******      Display all vehicle information     ******\n\
******************************************************\n");
}
void option2(){
printf("\n\
******************************************************\n\
***********      you have selected (2)     ***********\n\
******   Display available vehicles currently   ******\n\
******************************************************\n");
}

void option3(){
printf("\n\
**********************************************************************\n\
***********              you have selected (3)             ***********\n\
******   Display vehicles that will be available after x days   ******\n\
**********************************************************************\n");
}

void option4(){
printf("\n\
******************************************************\n\
***********      you have selected (4)     ***********\n\
******         Create a new reservation         ******\n\
******************************************************\n");
}

void option5(){
printf("\n\
******************************************************\n\
***********      you have selected (5)     ***********\n\
******             Add a new vehicle            ******\n\
******************************************************\n");
}
void option6(){
printf("\n\
***********************************************************************\n\
***********                you have selected (6)            ***********\n\
******    Search for a vehicle using the license plate number    ******\n\
***********************************************************************\n");
}void option7(){
printf("\n\
***************************************************************************************\n\
***********                          you have selected (7)                  ***********\n\
******     Sort and display all vehicles according to their daily rental price   ******\n\
***************************************************************************************\n");
}
void option8(){
printf("\n\
**********************************************************\n\
***********        you have selected (8)       ***********\n\
******   Display the top 3 most reserved vehicles   ******\n\
**********************************************************\n");
}
void option9(){
printf("\n\
******************************************************\n\
***********      you have selected (9)     ***********\n\
******         Display all reservations         ******\n\
******************************************************\n");
}
void option10(){
printf("\n\
******************************************************\n\
***********      you have selected (10)     **********\n\
******             Remove a vehicle             ******\n\
******************************************************\n");
}
void option11(){
printf("\n\
******************************************************\n\
***********      you have selected (11)     **********\n\
******            Cancel a reservation          ******\n\
******************************************************\n");
}
void option12(){
printf("\n\
*********************************************************************************\n\
***********                    you have selected (12)                  **********\n\
*****     Display clients who have rented a vehicle more than 3 times      ******\n\
*********************************************************************************\n");
}
void option13(){
printf("\n\
***************************************************************************************\n\
***********                       you have selected (13)                     **********\n\
*****    Save all reservations with a total cost exceeding x to a new file.      ******\n\
***************************************************************************************\n");
}
void option14(){
printf("\n\
***************************************************************************************\n\
***********                       you have selected (14)                     **********\n\
*****            Modify information for a vehicle using its plate number         ******\n\
***************************************************************************************\n");
}
void option15(){
printf("\n\
*************************************************************\n\
***********        you have selected (15)          **********\n\
******        search for client by phone number        ******\n\
************************************************************\n");
}

#endif // DESIGN_H_INCLUDED
