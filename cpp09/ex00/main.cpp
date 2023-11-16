#include <iostream>
#include "includes/BitcoinExchange.hpp"

bool FileFormatError(char *inFileName, std::ifstream& inFile, std::ifstream& btcDB) {

	std::string 	line;

	inFile.open(inFileName);
	btcDB.open("data.csv");

	if (!inFile.is_open()) {
	
        std::cerr << "Error: could not open the input file." << std::endl;
        return true;
    }
    if (!btcDB.is_open()) {

        inFile.close();
		std::cerr << "Error: could not open the database file." << std::endl;
		return true; 
	}

	if (std::getline(inFile, line)) {
		if (line != "date | value") {
			std::cerr << "Error: - wrong file format." << std::endl;
			return true;
		}
	}

	return false;
}


int main(int ac, char **av)
{
    BitcoinExchange btcExchange;
    std::ifstream   inFile, btcDB;

    if (ac != 2) {
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return 1;
	}

    if (FileFormatError(av[1], inFile, btcDB))
        return 1;

    btcExchange.fillBtcDBmap(btcDB);
    btcExchange.displayBtcStockExchangeRate(inFile);

    inFile.close();
	btcDB.close();
}