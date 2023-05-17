#include "Harl.hpp"

int     main(int ac, char **av)
{
	Harl    bot1;
	
	if (ac != 2)
	{
		std::cerr << "2 arguments required !" << std::endl;
		return 1;
	}
	bot1.complain(std::string(av[1]));
}
