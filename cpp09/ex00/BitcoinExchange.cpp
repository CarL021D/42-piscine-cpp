#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {

	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	 
	 (void)rhs;
	 return *this;
}

bool BitcoinExchange::storeFileContentIfValidFormat(char *inFile) {

	std::ifstream	inputFile(inFile);

	if (!inputFile) {
		std::string str(inFile);
		std::cerr << "Error: - " + str + " can not be opened" << std::endl;
		return (false); 
	}


	std::string line;
	if (std::getline(inputFile, line)) {
		if (line != "date | value") {
			std::cerr << "Error: - wrong file format" << std::endl;
			return false;
		}
		else {
			std::cerr << "Error: - empty file" << std::endl;
			return false;
		}
	}

	if (std::getline(inputFile, line) && !line.empty())
	{
		std::cerr << "Error: - wrong file format" << std::endl;
		return false;
	}

	std::string	delimiter = "|";
	while (std::getline(inputFile, line)) {
		size_t delPos = line.find(delimiter);
		std::string	key = "";
		std::string	value = "";
		if (delPos != std::string::npos) {
			key = line.substr(0, delPos);
			value = line.substr(delPos + 1);
		} else
			key = line;
		_data[key] = value;
	}

	std::map<std::string, std::string>::iterator it;
    for (it = _data.begin(); it != _data.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }


	return true;
}

void BitcoinExchange::displayBtcStockExchangePrice() {
	
}