#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct INFO{
int value;
struct INFO* nextValue;
}info;

int main(int argc, char** argv)
{
	info* infoStruct = malloc(sizeof(info));
	int a;
	
	while((a = getchar()) != EOF)
	{
		printf("HI");
		infoStruct->value = a;
		printf("%d\n",a);
		infoStruct->nextValue = malloc(sizeof(infoStruct));
		infoStruct = infoStruct->nextValue;
	}

	while(infoStruct->value != NULL)
	{
		printf("Value: %d",infoStruct->value);
		infoStruct = infoStruct->nextValue;
	}
}
