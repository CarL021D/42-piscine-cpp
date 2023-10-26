#include <iostream>
#include "includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btcExchange;
    
    if (btcExchange.checkValidFileFormat(ac, av[1]))
       btcExchange.displayBtcStockExchangeRate();
}