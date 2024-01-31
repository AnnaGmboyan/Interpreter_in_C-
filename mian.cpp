#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

int lines_count = 0;
int main_line = 0;

//containers
std::map<int, std::vector<std::string>> tokenized_lines_of_file;

#include "Prototypes.hpp"
#include "Tokenizer.hpp"


int main()
{
	std::ifstream read;
	read.open("Syntax.txt");
	if(!read.is_open()) {
			std::cout << "The File you want to read isn't open";
			exit(0);
	}
	tokenizer(read, lines_count, tokenized_lines_of_file);
	read.close();
	for(int i = 1; i < lines_count; ++i)
	{
			for(int j = 0; j < tokenized_lines_of_file[i].size(); ++j)
			{
					std::cout << tokenized_lines_of_file[i][j] << " ";
			}
			std::cout << std::endl;
	}
	std::cout << lines_count - 1 << std::endl;
	contains_main(tokenized_lines_of_file);
	valid_parentheses(tokenized_lines_of_file);


}

#include "Implementation.hpp"
