#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Only 1 argument is required" << std::endl;
		return 1;
	}
	for (unsigned int i = 0; i < strlen(av[1]); i++)
	{
		if (isupper(av[1][i]))
			av[1][i] = tolower(av[1][i]);
		else if (islower(av[1][i]))
			av[1][i] = toupper(av[1][i]);
	}
	std::cout << av[1] << std::endl;
}