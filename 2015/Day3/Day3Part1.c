#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<errno.h>
#include<stdbool.h>

// Each house has a position in space and a number of visits
typedef struct _HOUSEINFO
{
	int north;
	int south;
	int east;
	int west;
	int visit;
	struct _HOUSEINFO* nextHouse;
}HouseInfo;

// Update current house position
void CalculateCurrentPosition(char direction);

// Determine How many houses were visited once
unsigned long HousesVisitedOnce(HouseInfo* houseChain);

// Add house to houseChain
void AddHouse(HouseInfo* houseChain);

// Determine if a house has been visited previously
bool PreviousVisit(HouseInfo* houseChain);
	
HouseInfo currentHouse;
HouseInfo houseChain;

unsigned long count = 0;

int main(int argc, char** argv)
{
	// Read input into stdin
	freopen("input.txt","r",stdin);

	// Set current house location
	currentHouse.north = 0;
	currentHouse.south = 0;
	currentHouse.east = 0;
	currentHouse.west = 0;
	currentHouse.visit = -1;

	count++;

	houseChain = currentHouse;

	char direction;

	while(1)
	{
		direction = fgetc(stdin);
	
		if(feof(stdin))
			break;

		CalculateCurrentPosition(direction);

		if(PreviousVisit(&houseChain)==false)
		{
			count++;
			AddHouse(&houseChain);
		}

		else
		{
			//IncrementVisit(currentHouse);
		}

	}

	printf("The number of houses that were visited at least once: %lu\n",count);
}


void CalculateCurrentPosition(char direction)
{
	if(direction=='<')
	{
		currentHouse.west = currentHouse.west + 1;
		currentHouse.east = currentHouse.east - 1;
	}	

	else if(direction=='>')
	{
		currentHouse.east = currentHouse.east + 1;
		currentHouse.west = currentHouse.west - 1;
	}
	
	else if(direction=='^')
	{
		currentHouse.north = currentHouse.north + 1;
		currentHouse.south = currentHouse.south - 1;
	}
	
	else if(direction=='v')
	{
		currentHouse.south = currentHouse.south + 1;
		currentHouse.north = currentHouse.north + -1;
	}
}


unsigned long HousesVisitedOnce(HouseInfo* houseChain)
{
	if(houseChain->nextHouse == NULL)
	{
		return count;
	}

	else
	{
		printf("Count: %lu",count);	
		//count = count+1;
		//AddHouse(houseChain->nextHouse);
	}
}

void AddHouse(HouseInfo* houseChain)
{
	if(houseChain->nextHouse == NULL)
	{
		houseChain->nextHouse = malloc(sizeof(HouseInfo));
		*(houseChain->nextHouse) = currentHouse;
		printf("north: %d, south: %d, east: %d, west: %d\n",(houseChain->nextHouse)->north,(houseChain->nextHouse)->south,(houseChain->nextHouse)->east,(houseChain->nextHouse)->west);
	}

	else
	{	
		AddHouse(houseChain->nextHouse);
	}
}

bool PreviousVisit(HouseInfo* houseChain)
{
	if(houseChain->nextHouse == NULL)
		return false;

	else
	{
		if(houseChain->north == currentHouse.north &&
		   houseChain->south == currentHouse.south &&
		   houseChain->east == currentHouse.east &&
		   houseChain->west == currentHouse.west)
		   {
			printf("Been Here\n");
			return true; 
		   }

		PreviousVisit(houseChain->nextHouse);
	}
}
