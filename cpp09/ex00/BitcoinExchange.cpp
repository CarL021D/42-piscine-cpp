#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {

	if (_inputFile.is_open())
		_inputFile.close();
	 if (_btcDataBase.is_open())
		_btcDataBase.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {

	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	 
	 (void)rhs;
	 return *this;
}

bool BitcoinExchange::checkValidFileFormat(int ac, char *inFile) {

	std::string 	line;

	if (ac != 2) {
		std::cout << "Error: wrong number of arguments" << std::endl;
		return false;
	}

	_inputFile.open(inFile);
	_btcDataBase.open("data.csv");

	if (!_inputFile.is_open() || !_btcDataBase.is_open()) {
		std::string str(inFile);

		std::cerr << "Error: could not open file." << std::endl;
		return false; 
	}

	if (std::getline(_inputFile, line)) {
		if (line != "date | value") {
			std::cerr << "Error: - wrong file format." << std::endl;
			return false;
		}
	}
	return true;
}




void BitcoinExchange::displayBtcStockExchangeRate(char *btcDB, char *inFile) {
	
	(void)btcDB;
	(void)inFile;
	return ;
	

	std::ifstream	inputFile(inFile);
	std::string line;

	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		size_t delPos = line.find('|');

		std::string key = (delPos != std::string::npos) ? line.substr(0, delPos) : line;
		std::string value = (delPos != std::string::npos) ? line.substr(delPos + 1) : "";

		_data.insert(std::pair<std::string,std::string>(key, value));

		for (std::map<std::string, std::string>::const_iterator it = _data.begin(); it != _data.end(); ++it) {

			if (!lineFormatErrorCheck(line) && !dateErrorCheck(it->first) && !valueErrorCheck(it->second))
				std::cout << std::endl;
		}
		// TODO: - check date

		// TODO: - check value format

		// TODO: - look for the valid date

		/* if (dateValueCheck && valueFormatcheck)
				printBtcStockExchangeRate();
		*/





		// Prints the value and the key of the infile
		// std::map<std::string, std::string>::iterator it;
		// for (it = _data.begin(); it != _data.end(); ++it) {
		// 	std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
		// }

		// it = _data.begin();
		// _data.erase(it);
	}
}

bool BitcoinExchange::lineFormatErrorCheck(std::string value) const {
	std::cout << "Error: bad format." << std::endl;
	return value.empty();
}

bool BitcoinExchange::dateErrorCheck(std::string dateStr) const {
	
	std::string		year, month, day;
	size_t			delPos;

	delPos = dateStr.find('-');
	year = (delPos != std::string::npos) ? dateStr.substr(0, delPos) : "";
	size_t tmp = delPos + 1;
	delPos = dateStr.find('-', tmp);
	month = (delPos != std::string::npos) ? dateStr.substr(tmp, delPos - tmp) : ""; 
	day = (delPos != std::string::npos) ? dateStr.substr(delPos +  1) : ""; 

	// To remove ???
	year = removeFrontAndTraillingWhiteSpaces(year);
	month = removeFrontAndTraillingWhiteSpaces(month);
	day = removeFrontAndTraillingWhiteSpaces(day);

	if (year.empty() || month.empty() || day.empty()) {

		std::cout << "Error: bad input => " << dateStr << "." << std::endl;
		return true;	
	}

	if (valueIsOnlyDigits(year) || valueIsOnlyDigits(month) || valueIsOnlyDigits(day)) {
		
		std::cout << "Error: bad input => " << dateStr << "." << std::endl;
		return true;
	}

	if (nonExistentDateError(dateStr, year, month, day))
		return true;	

	return false;
}


bool BitcoinExchange::valueErrorCheck(const std::string& value) const {

	std::string truncValue = removeFrontAndTraillingWhiteSpaces(value);

	if (!valueIsOnlyDigits(value)) {
		std::cout << "Error: bad input => " << value << "." << std::endl;
		return true;
	}

	if (!isFloat(truncValue) ) {
		std::cout << "Error: bad input => " << value << "." << std::endl;
		return true;
	}
	return false;
}

		// _btcValue = stringIntoFloat(truncValue);


// UTILS

bool BitcoinExchange::valueIsOnlyDigits(const std::string& dateStr) const {

	for (std::string::const_iterator it = dateStr.begin(); it != dateStr.end(); ++it) {
		if (!isdigit(*it))
			return false;
	}
	return true;
}

const std::string BitcoinExchange::removeFrontAndTraillingWhiteSpaces(const std::string& str) const {

	std::string truncStr;

	size_t startPos = str.find_first_not_of(" \t");
	if (startPos != std::string::npos) {
		truncStr = str.substr(startPos);
		size_t endPos = truncStr.find_last_not_of(" \t");
		if (endPos != std::string::npos)
			truncStr = truncStr.substr(0, endPos + 1 ); // endPos is the last character that is not a white space
	}
	return truncStr;
}

bool BitcoinExchange::nonExistentDateError(const std::string& dateStr, const std::string& year, const std::string& month, const std::string& day) const {

	long yearDigits = stringIntoLong(year);
	long monthDigits = stringIntoLong(month);
	long dayDigits = stringIntoLong(day);

	if (month.size() > 2 || day.size() > 2)
		std::cout << "Error: bad input => " << dateStr << "." << std::endl;

	if (!intMaxIntMinInrangeCheck(yearDigits) || !intMaxIntMinInrangeCheck(monthDigits) || !intMaxIntMinInrangeCheck(dayDigits)) {
			std::cout << "Error: too large a number." << std::endl;
			return true;
	}

	if (monthDigits < 1 || monthDigits > 12) {
	
		std::cout << "Error: bad input => " << dateStr << "." << std::endl;
		return true;
	}
		
	if (dayDigits < 1 || ((monthDigits % 2) && dayDigits > 31) ||
		!((monthDigits % 2) && dayDigits > 30) || ((monthDigits == 2) && dayDigits > 28)) {
			
			std::cout << "Error: bad input => " << dateStr << "." << std::endl;
			return true;
	}
	return false;
}

bool BitcoinExchange::isFloat(const std::string &str) const {
	
	float value;
	return sscanf(str.c_str(), "%f", &value) == 1;
}

float BitcoinExchange::stringIntoFloat(std::string& str) const {
	
	char* end;
	const char* cstr = str.c_str();
	double result = std::strtod(cstr, &end);

	// Check for conversion errors
	if (*end != '\0') {
		// Handle the conversion error here, e.g., throw an exception or return a default value
		std::cerr << "Conversion error: " << str << std::endl;
		return -1.0; // Default value as a float
	}

	return static_cast<float>(result);
}

long BitcoinExchange::stringIntoLong(const std::string& str) const {
    char* end;
    const char* cstr = str.c_str();
    long result = std::strtol(cstr, &end, 10);

    // Check for conversion errors
    if (*end != '\0') {
        // Handle the conversion error here, e.g., throw an exception or return a default value
        std::cerr << "Conversion error: " << str << std::endl;
        return -1; // Default value as a long
    }

    return result;
}

bool BitcoinExchange::intMaxIntMinInrangeCheck(long nb) const {

	return (nb <= std::numeric_limits<int>::max() && nb >= std::numeric_limits<int>::min());
}
