#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char** argv)
{
	FILE* fileInput = fopen(argv[1],"r"); 
	int floor = 0;
	int floorCounter = 0;

	while(!feof(fileInput))
	{
		char parenthesis = fgetc(fileInput);
		
		if(parenthesis == '(')
			floor++;
		else if(parenthesis == ')')
			floor--;
		
		floorCounter++;

		if(floor == -1)
		{
			printf("In Basement: %d\n",floorCounter);
			break;
		}			
	}

	fclose(fileInput);
}
