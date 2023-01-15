#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int MAX_LINE_LENGTH = 100;
size_t bufferSize = sizeof(int);

int SurfaceArea(int length, int width, int height);
int SmallSide(int length, int width, int height);

int main(int argc, char** argv)
{
	FILE* inputFile = fopen(argv[1],"r");
	char* lineData = malloc(sizeof(char) * MAX_LINE_LENGTH + 1);
	char delimeter = 'x';
	char endoflineDelimeter[] = "\0";
	unsigned long totalPaper = 0;

	unsigned long length;
	unsigned long width;
	unsigned long height;

	while(getline(&lineData,&bufferSize,inputFile) != -1)
	{
		length = atoi(strtok(lineData,&delimeter));
		width = atoi(strtok(NULL,&delimeter));
		height = atoi(strtok(NULL,endoflineDelimeter));
		totalPaper = totalPaper + SurfaceArea(length,width,height) + SmallSide(length*width,width*height,height*length); 
	}

	printf("Total Paper: %lu \n",totalPaper);

	fclose(inputFile);
	return EXIT_SUCCESS;

}

int SurfaceArea(int length, int width, int height)
{
	return ((2*length*width) + (2*width*height) + (2*height*length));
}

int SmallSide(int length, int width, int height)
{
	int smallSide = length;
	
	if(smallSide>width)
		smallSide = width;

	if(smallSide>height)
		smallSide = height;

	return smallSide;
}
