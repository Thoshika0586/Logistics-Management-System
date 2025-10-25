#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define MAX_CITIES 35
#define NUM_VEHICLES 3

char cities[MAX_CITIES][50];
int distance[MAX_CITIES][MAX_CITIES];
int cityCount=0;

char vehicleType[NUM_VEHICLES][20]= {"Van","Truck","Lorry"};
int capacity[NUM_VEHICLES]= {1000,5000,10000};
int ratePerKm[NUM_VEHICLES]= {30,40,80};
int avgSpeed[NUM_VEHICLES]= {60,50,45};
int fuelEfficiency[NUM_VEHICLES]= {12,6,4};

void addCity(char cities[MAX_CITIES][50]);
void showCity(char cities[MAX_CITIES][50]);
void renameCity(char cities[MAX_CITIES][50]);
void removeCity(char cities[MAX_CITIES][50]);
void inputEditDistance(int distance[MAX_CITIES][MAX_CITIES]);
void showDistance(int distance[MAX_CITIES][MAX_CITIES]);
void storeVehicles(char vehicleType[NUM_VEHICLES][20],int capacity[NUM_VEHICLES],int ratePerKm[NUM_VEHICLES],int avgSpeed[NUM_VEHICLES],int fuelEfficiency[NUM_VEHICLES]);


int main()
{
    int choice;
    do
    {
        printf("\n====LOGISTICS MANAGEMENT SYSTEM====\n");
        printf("\n--City Management--\n");
        printf("1.Add City\n");
        printf("2.Show City\n");
        printf("3.Rename City\n");
        printf("4.Remove City\n");
        printf("\n--Distance Management--\n");
        printf("5.Input Or Edit Distance\n");
        printf("6.Show Distance\n");
        printf("\n--Vehicle Management--\n");
        printf("7.Store Vehicles\n");
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
            addCity(cities);
            break;

        case 2:
            showCity(cities);
            break;

        case 3:
            renameCity(cities);
            break;

        case 4:
            removeCity(cities);
            break;

        case 5:
            inputEditDistance(distance);
            break;

        case 6:
            showDistance(distance);
            break;

        case 7:
            storeVehicles(vehicleType,capacity,ratePerKm,avgSpeed,fuelEfficiency);
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
void addCity(char cities[MAX_CITIES][50])
{
    char newCity[50];
    if(cityCount>=MAX_CITIES)
    {
        printf("Maximum number of cities reached!\n");
        return;
    }
    printf("Enter city name:");
    scanf("%s",newCity);
    for(int i=0; i<cityCount; i++)
    {
        if(strcmp(cities[i],newCity)==0)
        {
            printf("City already exists!\n");
            return;
        }
    }
    strcpy(cities[cityCount],newCity);
    cityCount++;
    printf("City '%s' added successfully!(city ID:%d)\n",newCity,cityCount-1);
}
void showCity(char cities[MAX_CITIES][50])
{
    printf("\n----List Of Cities----\n");
    printf("======================\n");
    for(int i=0; i<cityCount; i++)
    {
        printf("%d.%s\n",i,cities[i]);
    }
}
void renameCity(char cities[MAX_CITIES][50])
{
    char newName[50];
    int cityId;

    if(cityCount==0)
    {
        printf("No cities available to rename!\n");
        return;
    }
    printf("Enter city ID to rename:");
    scanf("%d",&cityId);

    if(cityId<0||cityId>=cityCount)
    {
        printf("Invalid city ID!\n");
        return;
    }
    printf("Enter new city name:");
    scanf("%s",newName);
    strcpy(cities[cityId],newName);
    printf("City renamed successfully!\n");
}
void removeCity(char cities[MAX_CITIES][50])
{
    int cityId;

    if(cityCount==0)
    {
        printf("No cities available to remove!\n");
        return;
    }
    printf("Enter city ID to remove:");
    scanf("%d",&cityId);

    if(cityId<0||cityId>=cityCount)
    {
        printf("Invalid city ID!\n");
        return;
    }
    for (int i = cityId; i < cityCount - 1; i++)
    {
        strcpy(cities[i], cities[i + 1]);
    }

    for (int i = cityId; i < cityCount - 1; i++)
    {
        for (int j = 0; j < cityCount; j++)
        {
            distance[i][j] = distance[i + 1][j];
        }
    }

    for (int j = cityId; j < cityCount - 1; j++)
    {
        for (int i = 0; i < cityCount; i++)
        {
            distance[i][j] = distance[i][j + 1];
        }
    }

    cityCount--;
    printf("City Removed Successfully!\n");
}
void inputEditDistance(int distance[MAX_CITIES][MAX_CITIES])
{
    int d,src,dest;

    if(cityCount<2)
    {
        printf("Need at least two cities to set distances.\n");
    }
    printf("Enter city ID of first city:");
    scanf("%d",&src);
    printf("Enter city ID of second city:");
    scanf("%d",&dest);

    if(src<0||src>=cityCount||dest<0||dest>=cityCount)
    {
        printf("Invalid city ID!!\n");
        return;
    }
    if(src==dest)
    {
        distance[src][src]=0;
        printf("Distance from a city to itself must be zero.\n");
        return;
    }
    printf("Enter distance between %s and %s(km):",cities[src],cities[dest]);
    scanf("%d",&d);
    if(d<0)
    {
        printf("Distance must be positive!\n");
        return;
    }

    distance[src][dest]=distance[dest][src]=d;
    printf("Distance Updated!\n");
}
void showDistance(int distance[MAX_CITIES][MAX_CITIES])
{
    printf("\n\t\tDistance Table\n");
    printf("City         ");

    for(int i=0; i<cityCount; i++)
    {
        printf("%-12s  ",cities[i]);
    }
    printf("\n------------------------------------------------------------------\n");
    for(int j=0; j<cityCount; j++)
    {
        printf("%-12s  ",cities[j]);
        for(int i=0; i<cityCount; i++)
        {
            printf("%-12d  ",distance[i][j]);
        }
        printf("\n\n");
    }
}
void storeVehicles(char vehicleType[NUM_VEHICLES][20],int capacity[NUM_VEHICLES],int ratePerKm[NUM_VEHICLES],int avgSpeed[NUM_VEHICLES],int fuelEfficiency[NUM_VEHICLES])
{
    printf("\n\n");
    printf("| No | Vehicle | Capacity(kg) |Rate Per km(LKR) | Avg speed(km/h) | Fuel Efficiency(km/l) |");
    printf("\n===========================================================================================\n");
    for(int i=0; i<NUM_VEHICLES; i++)
    {
        printf("| %-2d | %-7s | %-12d | %-12d    | %-12d    | %-12d          |\n",i+1,vehicleType[i],capacity[i],ratePerKm[i],avgSpeed[i],fuelEfficiency[i]);


    }

}












