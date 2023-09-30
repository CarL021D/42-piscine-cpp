#include <iostream>
#include "includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btcExchange;
    
    if (ac != 3)
        std::cerr << "Error: could not open file" << std::endl; 
    else if (btcExchange.storeFileContentIfValidFormat(av[2]))
       return 1;
       // btcExchange.displayBtcStocks(av[1]);


}