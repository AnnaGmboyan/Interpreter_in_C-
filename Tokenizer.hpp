#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <sstream>

//Helper function for tokenizer
std::vector<std::string> own_tokenize(const std::string& line)
{
	
	std::stringstream ss(line);
	std::vector<std::string> tokenized_line;

	std::string current_word;

	while(ss >> current_word)
	{
			tokenized_line.push_back(current_word);
	}

	return tokenized_line;
}

//tokenizes all the lines of the file and  collects them in a map
void tokenizer(std::ifstream& read_file, int& current_line_number, std::map<int, std::vector<std::string>>& map)
{ 
		std::string current_line;
		while(!read_file.eof())
		{
				std::getline(read_file, current_line);
				map[++current_line_number] = own_tokenize(current_line);

		}
}
#endif //TOKENIZER_HPP
