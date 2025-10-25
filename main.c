#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define MAX_CITIES 35

char cities[MAX_CITIES][50];
int cityCount=0;

int main()
{
    int choice;
    do
    {
        printf("\n====LOGISTICS MANAGEMENT SYSTEM====\n");
        printf("\n--City Management--\n");
        printf("1.\n");
        printf("2.\n");
        printf("3.\n");
        printf("4.\n");
        printf("\n");
        printf("5.\n");
        printf("6.\n");
        printf("\n");
        printf("7.\n");
        printf("\n");
        printf("8.\n");
        printf("9.\n");
        printf("10.\n");
        printf("11.Exit\n");
        printf("\nEnter your choice(1-11):");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            break;

        case 10:
            break;

        case 11:
            printf("Exit....!\n");
            break;

        default:
            printf("Invalid choice!");
        }
    }
    while(choice!=11);


    return 0;
}


