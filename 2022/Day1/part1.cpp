#include<iostream>
#include<fstream>
#include<string>

int main(int argc, char** argv)
{
	std::ifstream inputFile("input.txt",std::ifstream::in);
	
	std::string calorie;
	int elfCalorie = 0;
	int holder = 0;

	while(!inputFile.eof())
	{
		std::getline(inputFile,calorie,'\n');
		
		if(calorie.length() != 0)
		{
			holder += std::stoi(calorie);
		}

		else
		{
			if(holder > elfCalorie)
				elfCalorie = holder;	
			holder = 0;
		}
	}

	std::cout << "An Elf carrying the most calories was holding " << elfCalorie << " calories!" << std::endl;

	return EXIT_SUCCESS;
}
