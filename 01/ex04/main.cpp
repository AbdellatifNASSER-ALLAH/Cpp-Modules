

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 4) 
		return (std::cout << "Usage: " << av[0] << " <filename> <replace> <with>" << std::endl, 1);

	std::ifstream	inputFile(av[1]);
	std::string	outputFileName = std::string(av[1]) + ".replace";
	std::ofstream	outputFile(outputFileName.c_str());

	if (inputFile.is_open() == false || outputFile.is_open() == false)
		return (std::cout << "Error: could not open file " << av[1] << std::endl, 1);

	std::string	line;
	std::string 	replace = av[2];
	std::string 	with = av[3];
	
	while(std::getline(inputFile, line))
	{
		size_t	pos = 0;
		while ((pos = line.find(replace, pos)) != std::string::npos)
		{
			line.erase(pos, replace.length());
			line.insert(pos, with);
			pos += with.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (0);
}
