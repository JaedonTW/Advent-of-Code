// Name: Jaedon Waller
// Date: 8/12/2021

// Note: Only run part1 or part2 at a time.

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>

using std::cout;
using std::ifstream;
using std::string;
using std::stringstream;
using std::endl;

int FuelAmount;

/*

Part1

int main(int argc, char** argv)
{
	ifstream InputFile;
	InputFile.open("Day1Input1.txt",ifstream::in);

	string FuelModule;

	while(getline(InputFile,FuelModule))
	{
		FuelAmount = FuelAmount + std::floor(stoi(FuelModule)/3) - 2;
	}

	InputFile.close();

	cout<<"Fuel Amount: "<<FuelAmount<<"!"<<std::endl;

	return 0;
}
*/

/*

Part2

// CalculateFuel wil be used recursively to calculate
// the "Fuel for the Fuel" as described by the problem.

int CalculateFuel(int Fuel)
{
	int FuelToReturn = std::floor(Fuel)/3-2;

	if(FuelToReturn<=0)
	{
		return 0;
	}

	cout<<Fuel<<" ";
	FuelAmount = FuelAmount + FuelToReturn;
	CalculateFuel(FuelToReturn);
	return 0;
}


int main(int argc, char** argv)
{
	ifstream InputFile;
	InputFile.open("Day1Input1.txt",ifstream::in);

	string FuelModule;

	while(getline(InputFile,FuelModule))
	{
		CalculateFuel(std::stoi(FuelModule));
		cout<<endl;
	}

	InputFile.close();

	cout<<"New Fuel Amount: "<<FuelAmount<<"!"<<endl;

	return 0;
}
*/
