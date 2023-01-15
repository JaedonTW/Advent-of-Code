#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INPUTLENGTH 709

typedef struct DIRECTION
{
	char currentDirection[6];
	int units;
	struct DIRECTION* right;
	struct DIRECTION* left;
}DirectionAway;

DirectionAway direction;

void PrintValue(DirectionAway* directionAway)
{
	for(int i=0; i<4; i++)
	{
		printf("Direction: %s | Unit: %d\n",directionAway->currentDirection,directionAway->units);
		directionAway = directionAway->left;
	}
}

void Turn(DirectionAway* directionAway, char* directionMagnitude)
{
	printf("Current Dir: %s",directionAway->currentDirection);

	char* magnitudeStr = malloc(sizeof(char)* 10);
	int magnitude;

	for(int i=1; i<10; i++)
	{
		if(directionMagnitude[i] != ',')
		{
			magnitudeStr[i-1] = directionMagnitude[i];
		}
		
		else
		{
			break;
		}
	}

	magnitude = atoi(magnitudeStr);

	if(directionMagnitude[0] == 'L')
	{	
		directionAway = directionAway->left;
		directionAway->units += magnitude;
		printf("Adding %s\n",directionAway->currentDirection);
	}

	else if(directionMagnitude[0] == 'R')
	{		
		directionAway = directionAway->right;
		directionAway->units += magnitude;
		printf("Adding %s\n",directionAway->currentDirection);
	}
	
	else
	{
		printf("Unknown Direction: %c\n",directionMagnitude[0]);
	}
}

void ProcessData(DirectionAway* directionAway, char* str)
{
	char* directionMagnitude = malloc(sizeof(char)* 10);
	char* remember = directionMagnitude;
		
	directionMagnitude = strtok(str," ");
	Turn(directionAway,directionMagnitude);
	
	while(1)
	{	
		directionMagnitude = strtok(NULL, " ");
		
		if(directionMagnitude != NULL)
		{
			Turn(directionAway,directionMagnitude);
		}	

		else
		{
			break;
		}	
	}

	free(remember);
}

void CreateDoubleCircleLL(DirectionAway* directionAway)
{
	char* directions[4] = {"north","east","south","west"};

	DirectionAway* start = directionAway;

	for(int i=0; i<4; i++)
	{
		strcpy(directionAway->currentDirection,directions[i]);
		directionAway->units = 0;
		if(i != 3)
		{
			directionAway->right = malloc(sizeof(DirectionAway));
			directionAway = directionAway->right;
		}
	}

	DirectionAway* previous = directionAway;	
	directionAway->right = start;
	directionAway = start;
	
	for(int i=0; i<4; i++)
	{
		directionAway->left = previous;
		previous = directionAway;
		directionAway = directionAway->right;
	}

	directionAway = start;
}
int main(int argc, char** argv)
{	
	// Check length of input
	// int length = 0;
	// while(getchar()!=EOF)
	// {
		// length++;
	// }
	// Comes out to 709
	// printf("Length of string: %d\n",length);

	char* input = malloc(sizeof(char)* 709); 
	fgets(input,INPUTLENGTH,stdin); // Grab Input
	
	//DirectionAway direction;
	CreateDoubleCircleLL(&direction); // Create Double Circle LL
	ProcessData(&direction,input); // Process Data
	PrintValue(&direction);

	return EXIT_SUCCESS;
}
