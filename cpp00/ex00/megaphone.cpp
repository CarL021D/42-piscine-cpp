#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Only 1 argument is required" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++)
	{
		for (unsigned int j = 0; av[i][j]; j++)
		{
			if (islower(av[i][j]))
				std::cout << (char)toupper(av[i][j]);
			else
				std::cout << av[i][j];
		}
	}
	std::cout << std::endl;
}