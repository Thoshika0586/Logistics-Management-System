#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define MAX_CITIES 35

char cities[MAX_CITIES][50];
int distance[MAX_CITIES][MAX_CITIES];
int cityCount=0;

void addCity(char cities[MAX_CITIES][50]);
void showCity(char cities[MAX_CITIES][50]);
void renameCity(char cities[MAX_CITIES][50]);
void removeCity(char cities[MAX_CITIES][50]);
void inputEditDistance(int distance[MAX_CITIES][MAX_CITIES]);

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










