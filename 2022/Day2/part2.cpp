#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<sstream>

int main(int argc, char** argv)
{
	std::map<char,const char*> gameMap;
	gameMap.insert(std::pair<char,const char*>('A',"XYZ321"));
	gameMap.insert(std::pair<char,const char*>('B',"XYZ132"));
	gameMap.insert(std::pair<char,const char*>('C',"XYZ213"));
	// numbers above represent what to return in lose/win/draw cases respectively

	std::ifstream inputFile("input.txt",std::ifstream::in);
	std::string line;

	char opponent;
	char self;
	int score = 0;
	
	auto thing = [score,gameMap](char oppChoice, char myChoice)
	{
		// Draw
		if(myChoice == 'Y')
		{
			return  gameMap.find(oppChoice)->second[5] - '0' + 3;
		}

		// I lose
		else if(myChoice == 'X') 
		{	
			return gameMap.find(oppChoice)->second[3] - '0';
		}

		// I win
		else
		{	
			return gameMap.find(oppChoice)->second[4] - '0' + 6;
		}
	};

	while(true)
	{
		getline(inputFile,line);
		
		if(inputFile.eof())
			break;

		std::stringstream inputStream(line);
		inputStream.get(opponent);
		inputStream.get();
		inputStream.get(self);
		score = score + thing(opponent,self);
	}

	std::cout<<"The Score: "<<score<<std::endl;

	return EXIT_SUCCESS;
}
