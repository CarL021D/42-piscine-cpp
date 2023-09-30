#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	 
	 return *this;
}

bool BitcoinExchange::storeFileContent(char *inFile) {

	std::ifstream	inputFile(inFile);

	if (!inputFile) {
		std::string str = str(inFile);
		std::cerr << "Error: - " + str + " can not be opened" << std::endl;
		return (false); 
	}


	std::string line;
	if (std::getline, line) {
		if (line != "date | value") {
			std::cerr << "Error: - wrong file format" << std::endl;
			return (false);
		}
		else {
			std::cerr << "Error: - empty file" << std::endl;
			return false;
		}
	}

	if (std::getline(inFile, line) && !line.empty())
	{
		std::cerr << "Error: - wrong file format" << std::endl;
		return false;
	}

	std::string	delimiter = "|";
	while (std::getline(inFile, line)) {
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

}

void BitcoinExchange::fileContentDisplay() {
	
}