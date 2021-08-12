#include<cstdlib>
#include<iostream>
#include<vector>
#include<fstream>

using std::cout;
using std::endl;

int main(void)
{
	cout<<"Day 1"<<endl;

	/*
		Open the file to read
	*/
	std::ifstream fileStream;
	fileStream.open("Day1Input.txt");
	
	char holder;
	int character_Index = 0;
	int floor = 0;
	
	while(fileStream.eof() == false)
	{
		holder = fileStream.get();
		character_Index++;
		
		if(holder == '(')
		{
			floor++;
		}
		
		else if(holder == ')')
		{
			floor--;
		}
		
		if(floor == -1)
		{
			cout<<"Santa is in the basement at character index: "<<character_Index<<endl;
		}
	}
	
	cout<<"Santa is on floor: "<<floor<<endl;
	
	return EXIT_SUCCESS;
}