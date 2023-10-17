#include <iostream>
#include "includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btcExchange;
    std::ifstream   inputFile;
    std::ifstream   btcDataBase;
    
    if (btcExchange.checkValidFileFormat(ac, av[1]))
       std::cout << std::endl << "Success" << std::endl;
       // btcExchange.displayBtcStocks(av[1]);


}