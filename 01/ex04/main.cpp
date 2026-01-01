
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int	main(int ac, char **av)
{
	if (ac != 4) 
		return (std::cout << "Usage: " << av[0] << " <filename> <replace> <with>" << std::endl, 1);

	if (!av[2][0])
		return (std::cout << "Error: <replace> strings must not be empty." << std::endl, 1);

	std::ifstream	inputFile(av[1]);
	std::string	outputFileName = std::string(av[1]) + ".replace";
	std::ofstream	outputFile(outputFileName.c_str());

	if (inputFile.is_open() == false || outputFile.is_open() == false)
		return (std::cout << "Error: could not open file " << av[1] << std::endl, 1);

	std::stringstream buffer;
	buffer << inputFile.rdbuf();
	std::string content = buffer.str();
	
	std::string replace = av[2];
	std::string with = av[3];
	
	size_t pos = 0;
	while ((pos = content.find(replace, pos)) != std::string::npos)
	{
		content.erase(pos, replace.length());
		content.insert(pos, with);
		pos += with.length();
	}
	
	outputFile << content;
	inputFile.close();
	outputFile.close();
	return (0);
}
