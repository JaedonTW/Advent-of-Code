#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>

using namespace std;

class Person
{
	private:
	/*
		A person will have a current direction
		they are facing. This will be an integer
		represnting direction in degrees; follow
		the unit circle representation.
	*/
	int current_Direction;
	
	/*
		A person will have a number of
		steps taken in each of the corresponding
		directions.
	*/
	int east_Distance;
	int west_Distance;
	int north_Distance;
	int south_Distance;
	
	/*
		Constructor to set initial direction
	*/
	public:Person(int current_Direction)
	{
		this->current_Direction = current_Direction;
		
		east_Distance = 0;
		west_Distance = 0;
		north_Distance = 0;
		south_Distance = 0;
	}
	
	public:void set_Current_Direction(int num)
	{
		current_Direction = current_Direction + num;
		
		if(current_Direction == 360)
		{
			current_Direction = 0;
		}
		
		else if(current_Direction == -90)
		{
			current_Direction = 270;
		}
	}
	
	public:void update_Total_Distance(int distance_To_Add)
	{
		if(current_Direction == 0)
		{
			east_Distance = east_Distance + distance_To_Add;
		}
		
		else if(current_Direction == 90)
		{
			north_Distance = north_Distance + distance_To_Add;
		}
		
		else if(current_Direction == 180)
		{
			west_Distance = west_Distance + distance_To_Add;
		}
		
		else if(current_Direction == 270)
		{
			south_Distance = south_Distance + distance_To_Add;
		}
	}
	
	public:int get_Total_Distance()
	{
		int total_Distance = abs((east_Distance - west_Distance)) + abs((north_Distance - south_Distance));
		cout<<east_Distance<<endl;
		cout<<west_Distance<<endl;
		cout<<north_Distance<<endl;
		cout<<south_Distance<<endl;
		return total_Distance;
	}
};


int main(int argc, char** argv)
{
	
	ifstream file_Object;
	file_Object.open("Day1Input.txt");
	Person person(90);
	
	string string_Input;
	string direction;
	string distance;
	
	while(file_Object.eof()==false)
	{
		getline(file_Object,string_Input,' ');
		direction = string_Input[0];
		distance = string_Input[1];
		
		/*
			Turn Left
		*/
		if(direction.compare("L")==0)
		{
			person.set_Current_Direction(90);
		}
		
		/*
			Turn right
		*/
		else if(direction.compare("R")==0)
		{
			person.set_Current_Direction(-90);	
		}
		
		person.update_Total_Distance(stoi(distance));
	}
	
	cout<<"The total distance:" <<person.get_Total_Distance()<<endl;
	return EXIT_SUCCESS;	
}
