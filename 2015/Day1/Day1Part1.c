#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char** argv)
{
	FILE* fileInput = fopen(argv[1],"r"); 
	int floor = 0;

	while(!feof(fileInput))
	{
		char parenthesis = fgetc(fileInput);
		
		if(parenthesis == '(')
			floor++;
		else if(parenthesis == ')')
			floor--;
	}

	fclose(fileInput);
	printf("Final Floor: %d\n",floor);
}
