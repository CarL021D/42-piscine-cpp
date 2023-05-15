#include <iostream>
#include <cstdint>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "4 arguments required!" << std::endl;
		return 1;
	}
	std::ifstream	infile(av[1]);
	if (!infile.is_open())
	{
		std::cerr << "Error: failed to open file!" << std::endl;
		return 1;
	}
	std::ostream outfile((std::string)av[1] + ".replace");
	// if (!outfile)
	// {
	// 	std::cerr << "Error: failed to create file!" << std::endl;
	// 	return 1;
	// }
	std::string	fileContent = std::getline(infile, fileContent);

	for (findRet == fileContent.find(); findRet != -1)
	{





	}
}