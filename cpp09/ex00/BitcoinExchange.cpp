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

bool BitcoinExchange::checkValidFormatFile(int ac, char *inFile) {

	std::ifstream	inputFile(inFile);
	std::string line;

	if (ac != 3 || !inputFile) {
		std::string str(inFile);
		std::cerr << "Error: could not open file" << std::endl;
		return false; 
	}

	if (std::getline(inputFile, line)) {
		if (line != "date | value") {
			std::cerr << "Error: - wrong file format" << std::endl;
			return false;
		}
	}
	return true;

	while (std::getline(inputFile, line)) {
		size_t delPos = line.find('|');
		// std::string	key = "";
		// std::string	value = "";
		// if (delPos != std::string::npos) {
		// 	key = line.substr(0, delPos);
		// 	value = line.substr(delPos + 1);
		// } else
		// 	key = line;
		// _data[key] = value;
		std::string key = (delPos != std::string::npos) ? line.substr(0, delPos) : line;
        std::string value = (delPos != std::string::npos) ? line.substr(delPos + 1) : "";
        _data[key] = value;
	
		std::map<std::string, std::string>::iterator it;
		for (it = _data.begin(); it != _data.end(); ++it) {
			std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
		}

		it = _data.begin();
		_data.erase(it);
	}



	return true;
}

void BitcoinExchange::displayBtcStockExchangePrice(char *inFile) {
	std::ifstream	inputFile(inFile);
	std::string line;

	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		size_t delPos = line.find('|');


		// std::string	key = "";
		// std::string	value = "";
		// if (delPos != std::string::npos) {
		// 	key = line.substr(0, delPos);
		// 	value = line.substr(delPos + 1);
		// } else
		// 	key = line;
		// _data[key] = value;
		std::string key = (delPos != std::string::npos) ? line.substr(0, delPos) : line;
        std::string value = (delPos != std::string::npos) ? line.substr(delPos + 1) : "";
        _data[key] = value;
	
		// TODO: - check format

		// TODO: - look for date

		std::map<std::string, std::string>::iterator it;
		for (it = _data.begin(); it != _data.end(); ++it) {
			std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
		}

		it = _data.begin();
		_data.erase(it);
	}
}