#include <iostream>
#include "includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btcExchange;
    
    if (btcExchange.checkValidFileFormat(ac, av[1])) {
       std::cout << std::endl << "Success" << std::endl;
       btcExchange.displayBtcStockExchangeRate();
    }
    else
       std::cout << std::endl << "Failure" << std::endl;


}