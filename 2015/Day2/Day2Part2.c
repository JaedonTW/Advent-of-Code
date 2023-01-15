#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int MAX_LINE_LENGTH = 100;
size_t bufferSize = sizeof(unsigned long);

unsigned long RibbonLength(unsigned long length, unsigned long width, unsigned long height);
unsigned long BowLength(unsigned long length, unsigned long width, unsigned long height);

int main(int argc, char** argv)
{
	FILE* inputFile = fopen(argv[1],"r");
	char* lineData = malloc(sizeof(char) * MAX_LINE_LENGTH + 1);
	char delimeter = 'x';
	char endoflineDelimeter[] = "\0";
	unsigned long totalRibbon = 0;

	unsigned long length;
	unsigned long width;
	unsigned long height;

	while(getline(&lineData,&bufferSize,inputFile) != -1)
	{
		length = atoi(strtok(lineData,&delimeter));
		width = atoi(strtok(NULL,&delimeter));
		height = atoi(strtok(NULL,endoflineDelimeter));
		totalRibbon = totalRibbon + RibbonLength(length,width,height) + BowLength(length,width,height); 
	
		printf("Length=%lu  Width=%lu  Height=%lu \n ",length,width,height);
	}

	printf("Total Ribbon: %lu \n",totalRibbon);

	fclose(inputFile);
	return EXIT_SUCCESS;

}

unsigned long RibbonLength(unsigned long length, unsigned long width, unsigned long height)
{
	// Make the greatest value -1

	int smallSideA = length;
	int smallSideB = width;
	int smallSideC = height;

	if(smallSideA>=smallSideB && smallSideA>=smallSideC)
		smallSideA = -1;

	else if(smallSideB>=smallSideA && smallSideB>=smallSideC)
		smallSideB = -1;

	else
	{
		smallSideC = -1;
	}
		
	int arr[] = {smallSideA,smallSideB,smallSideC};

	int i;
	int result = 0;

	for(i=0;i<3;i++)
	{
		if(arr[i]>=0)
		{
			result = result + 2*arr[i];
		}
	}
	
	return result;
}

unsigned long BowLength(unsigned long length, unsigned long width, unsigned long height)
{
	return length*width*height;
}
