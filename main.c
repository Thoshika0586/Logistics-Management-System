#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define MAX_CITIES 35
#define NUM_VEHICLES 3
#define FUEL_PRICE 310.0  //LKR per liter
#define MAX_DELIVERIES 50

char cities[MAX_CITIES][50];
int distance[MAX_CITIES][MAX_CITIES];
int cityCount=0;
int deliveryCount=0;

char vehicleType[NUM_VEHICLES][20]= {"Van","Truck","Lorry"};
int capacity[NUM_VEHICLES]= {1000,5000,10000};
int ratePerKm[NUM_VEHICLES]= {30,40,80};
int avgSpeed[NUM_VEHICLES]= {60,50,45};
int fuelEfficiency[NUM_VEHICLES]= {12,6,4};

int sourceCity[MAX_DELIVERIES];
int destinationCity[MAX_DELIVERIES];
int weight[MAX_DELIVERIES];
int vehicleId[MAX_DELIVERIES];
float deliveryCost[MAX_DELIVERIES];
float deliveryTime[MAX_DELIVERIES];
float fuelUsed[MAX_DELIVERIES];
float fuelCost[MAX_DELIVERIES];
float totalCost[MAX_DELIVERIES];
float profit[MAX_DELIVERIES];
float customerCharge[MAX_DELIVERIES];



void addCity(char cities[MAX_CITIES][50]);
void showCity(char cities[MAX_CITIES][50]);
void renameCity(char cities[MAX_CITIES][50]);
void removeCity(char cities[MAX_CITIES][50]);
void inputEditDistance(int distance[MAX_CITIES][MAX_CITIES]);
void showDistance(int distance[MAX_CITIES][MAX_CITIES]);
void storeVehicles(char vehicleType[NUM_VEHICLES][20],int capacity[NUM_VEHICLES],int ratePerKm[NUM_VEHICLES],int avgSpeed[NUM_VEHICLES],int fuelEfficiency[NUM_VEHICLES]);
void addDelivery(char cities[MAX_CITIES][50],char vehicleType[NUM_VEHICLES][20],int distance[MAX_CITIES][MAX_CITIES],int capacity[NUM_VEHICLES],int ratePerKm[NUM_VEHICLES],int avgSpeed[NUM_VEHICLES],int fuelEfficiency[NUM_VEHICLES]);
void deliveryRecords();

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
        printf("\n--Delivery Request Handling--\n");
        printf("8.Add Delivery\n");
        printf("9.Delivery Records\n");
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
            addDelivery(cities,vehicleType,distance,capacity,ratePerKm,avgSpeed,fuelEfficiency);
            break;

        case 9:
            deliveryRecords();
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
void addDelivery(char cities[MAX_CITIES][50],char vehicleType[NUM_VEHICLES][20],int distance[MAX_CITIES][MAX_CITIES],int capacity[NUM_VEHICLES],int ratePerKm[NUM_VEHICLES],int avgSpeed[NUM_VEHICLES],int fuelEfficiency[NUM_VEHICLES])
{
    int src,dest,w,vId;
    if(deliveryCount>=MAX_DELIVERIES)
    {
        printf("Maximum number of deliveries reached!\n");
        return;
    }
    if(cityCount<2)
    {
        printf("Not enough cities.\n");
        return;
    }
    printf("Enter source city ID:");
    scanf("%d",&src);
    printf("Enter destination city ID:");
    scanf("%d",&dest);

    if(src<0||src>=cityCount||dest<0||dest>=cityCount||src==dest)
    {
        printf("Invalid city ID!!\n");
        return;
    }
    printf("Enter delivery order weight(kg):");
    scanf("%d",&w);

    if(w<=0)
    {
        printf("Weight must be positive!\n");
        return;
    }
    printf("Enter vehicle type for delivery(1-3):");
    scanf("%d",&vId);

    if(vId<1||vId>NUM_VEHICLES)
    {
        printf("Invalid vehicle type!\n");
        return;
    }
    if(w>capacity[vId-1])
    {
        printf("Weight exceeds vehicle capacity of %s!\n",vehicleType[vId-1]);
        return;
    }
     float dCost = distance[src][dest] * ratePerKm[vId-1] * (1.0 + (float)w/10000.0);
    float dTime = (float)distance[src][dest] / avgSpeed[vId-1];
    float fUsed = (float)distance[src][dest] / fuelEfficiency[vId-1];
    float fCost = fUsed * FUEL_PRICE;
    float tCost = dCost + fCost;
    float dprofit = dCost * 0.25;
    float custCharge = tCost + dprofit;

    sourceCity[deliveryCount] = src;
    destinationCity[deliveryCount] = dest;
    weight[deliveryCount] = w;
    vehicleId[deliveryCount] = vId;
    deliveryCost[deliveryCount] = dCost;
    deliveryTime[deliveryCount] = dTime;
    fuelUsed[deliveryCount] = fUsed;
    fuelCost[deliveryCount] = fCost;
    totalCost[deliveryCount] = tCost;
    profit[deliveryCount] = dprofit;
    customerCharge[deliveryCount] = custCharge;

    deliveryCount++;
    printf("Delivery added successfully!\n");
}
void deliveryRecords()
{
    if(deliveryCount==0)
    {
        printf("No deliveries recorded!\n");
        return;
    }
    for(int i=0; i<deliveryCount; i++)
    {

        printf("\n\nDelivery number %d\n",i+1);
        printf("\n======================================================\n");
        printf("DELIVERY COST ESTIMATION\n");
        printf("\n------------------------------------------------------\n");
        printf("From: %s\n",cities[sourceCity[i]]);
        printf("To: %s\n",cities[destinationCity[i]]);
        printf("Minimum Distance: %d km\n",distance[sourceCity[i]][destinationCity[i]]);
        printf("Vehicle: %s\n",vehicleType[vehicleId[i]-1]);
        printf("Weight: %d kg\n",weight[i]);
        printf("\n------------------------------------------------------\n");
        printf("Base Cost: %d*%d*(1+%d/10000)=%.2f LKR\n",distance[sourceCity[i]][destinationCity[i]],ratePerKm[vehicleId[i]-1],weight[i],deliveryCost[i]);
        printf("Fuel Used: %.2f L\n",fuelUsed[i]);
        printf("Fuel Cost: %.2f LKR\n",fuelCost[i]);
        printf("Operational Cost: %.2f LKR\n",totalCost[i]);
        printf("Profit: %.2f LKR\n",profit[i]);
        printf("Customer Charge: %.2f LKR\n",customerCharge[i]);
        printf("Estimated Time: %.2f hours\n",deliveryTime[i]);
        printf("\n======================================================\n");
    }
}
















