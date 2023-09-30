#include <iostream>
#include "includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btcExchange;
    
    if (ac != 2)
        std::cerr << "Error: could not open file" << std::endl; 
    else if (btcExchange.checkValidFormatFile(av[1]))
       return 1;
       // btcExchange.displayBtcStocks(av[1]);


}