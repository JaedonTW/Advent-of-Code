#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
 
std::vector<int> InsertionSort(std::vector<int> vec)
{
	for(int i = 1 ; i < vec.size() ; i++)
	{
		int j = i;
	
		while(vec[j]<vec[j-1] && j>0)
		{		
			int holder = vec[j];
			vec[j] = vec[j-1];
			vec[j-1] = holder;
			j--;
		}
	}

	return vec;
}

int main(int argc, char** argv)
{
	std::ifstream inputFile("input.txt",std::ifstream::in);
	std::string calorie;
	
	int holder = 0;
	std::vector<int> everyone;

	while(!inputFile.eof())
	{
		std::getline(inputFile,calorie,'\n');
		
		if(calorie.length() != 0)
		{
			holder += std::stoi(calorie);
		}

		else
		{
			everyone.push_back(holder);
			holder = 0;
		}
	}

	std::vector<int> sorted = InsertionSort(everyone);
	for_each(sorted.begin(),sorted.end(),[](int i){std::cout << i << std::endl;});

	std::cout<<"Third Most: " << sorted[sorted.size()-3] << std::endl;
	std::cout<<"Second Most: " << sorted[sorted.size()-2] << std::endl;
	std::cout<<"Most: " << sorted[sorted.size()-1] << std::endl;

	return EXIT_SUCCESS;
}
