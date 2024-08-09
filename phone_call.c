#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

char num[12] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '#'};

long long int phoneNo = 0;
int milliSec = 0;

int phone_Number[10];

//The visual structure of dial pad
void dialPad()
{

    system("cls");
    printf(" \n\n     DIAL PAD \n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", num[1], num[2], num[3]);

    printf("*****|*****|*****\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", num[4], num[5], num[6]);

    printf("*****|*****|*****\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", num[7], num[8], num[9]);

    printf("*****|*****|*****\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", num[10], num[0], num[11]);

    printf("     |     |     \n\n");
}

//To dial a number --> stores the phone number
void dial()
{
    dialPad();
    printf("\n Enter the phone number: ");
    scanf("%lld", &phoneNo);
}

//Generate a random number from 2 to 10
int random_time()
{
    int greater = 10;
    int smallest = 2;
    srand(time(NULL)); //for different random number
    int r = rand() % (greater - smallest + 1) + smallest;
    milliSec = 1000 * r; //converting into milli sec
    return milliSec;
}

//To delay the process of ringing after dialing
void delay()
{
    int time = 0;
    time = random_time();
    clock_t startTime = clock();
    while (clock() < startTime + time)
        ;
}

//Create sound
void sound()
{
    int time = 0;
    time = random_time();
    Beep(500, time);
    Beep(500, time);
}

//Ending a call
char end_call()
{
    printf("End the call (Y/N) \n");
    char input;
    scanf("%c", &input);
    return input;
}

//Contians calling
void call()
{
    printf("Calling......\n");
    delay(); //to delay the process
    printf("Ringing.......\n");
    sound();
    printf("Call Connected\n");

    char input1;
    input1 = end_call();

    if (input1 == 'Y'){
        printf("Call Ended.\n");
    }
    else if (input1 == 'N')
    {
        printf("You have spend way more time on call than studying..\n");
        end_call();
    }
}

//Generate random phone number
void random_phone_number()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        phone_Number[i] = (rand() % 9);
    }
}

//To make the anonymous call
void anonymous()
{
    random_phone_number();

    printf("Calling from ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", phone_Number[i]);
    }
    delay();
    printf("\nRinging.......\n");
    sound();
    printf("Connected.......\n");
    char input1;
    input1 = end_call();

    if (input1 == 'Y')
        printf("Call Ended.\n");
    else if (input1 == 'N')
    {
        printf("You have spend way more time on call than studying..\n");
        end_call();
    }
}

int main()
{
    int choice;
    do
    {
        printf(" 1. Dial a number \n");
        printf(" 2. Make a call \n");
        printf(" 3. Make a Anonymous call \n");
        printf("Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            dial();
            break;
        case 2:
            call();
            break;
        case 3:
            anonymous();
            break;
        }

    } while (choice < 4);

    return 0;
}