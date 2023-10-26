#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {

	if (_inFile.is_open())
		_inFile.close();
	 if (_btcDB.is_open())
		_btcDB.close();
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

	_inFile.open(inFile);
	_btcDB.open("data.csv");

	if (!_inFile.is_open() || !_btcDB.is_open()) {
		std::string str(inFile);

		std::cerr << "Error: could not open file." << std::endl;
		return false; 
	}

	if (std::getline(_inFile, line)) {
		if (line != "date | value") {
			std::cerr << "Error: - wrong file format." << std::endl;
			return false;
		}
	}
	return true;
}




void BitcoinExchange::displayBtcStockExchangeRate() {
	
	// (void)_btcDB;
	// (void)inFile;
	// return ;
	

	// std::ifstream	inputFile(inFile);
	// inFile(inFile);
	std::string line;

	while (std::getline(_inFile, line)) {
		size_t delPos = line.find('|');

		std::string key = (delPos != std::string::npos) ? line.substr(0, delPos) : line;
		std::string value = (delPos != std::string::npos) ? line.substr(delPos + 1) : "";

		_data.insert(std::pair<std::string,std::string>(key, value));

		for (std::map<std::string, std::string>::const_iterator it = _data.begin(); it != _data.end();) {

			if (lineFormatError(key, value) || dateFormatError(it->first) || valueFormatError(it->second)) {
				it = _data.erase(it);
				continue ;
			}
			// display btc closest value
			// std::cout << "SUCCESS" << std::endl;

			displayBtcValue();
			it = _data.erase(it);
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

void	BitcoinExchange::displayBtcValue() {

	std::string line, dbYear, dbMonth, dbDay;
	long yearDigits, monthDigits, dayDigits, prevYear, prevMonth, prevDay;

	_btcDB.seekg(0, std::ios::beg);
	std::getline(_btcDB, line);

	while (std::getline(_btcDB, line)) {
		
		size_t delPos = line.find(',');
		std::string dbDate = (delPos != std::string::npos) ? line.substr(0, delPos) : line;
		std::string dbValue = (delPos != std::string::npos) ? line.substr(delPos + 1) : "";

		delPos = dbDate.find('-');
		dbYear = dbDate.substr(0, delPos);
		size_t tmp = delPos + 1;
		delPos = dbDate.find('-', tmp);
		dbMonth = dbDate.substr(tmp, delPos - tmp); 
		dbDay = dbDate.substr(delPos +  1); 

		// std::cout << std::endl << "dbVal: " << dbValue << std::endl;
		// std::cout << "btcCount: " << _btcCount << std::endl;
		// std::cout << "res: " << _btcCount * stringIntoLong(dbValue) << std::endl;

		yearDigits = stringIntoFloat(dbYear);
		monthDigits = stringIntoFloat(dbMonth);
		dayDigits = stringIntoFloat(dbDay);

		//  float result = _btcCount * stringIntoFloat(dbValue);
		// std::cout << "res as float " << result << std::endl;
		if (yearDigits == _year && monthDigits == _month && dayDigits == _day) {
			std::cout << _year << "-" << _month << "-" << _day << " => " << _btcCount << " = " << _btcCount * stringIntoFloat(dbValue) << std::endl;
			return ;
		}
		
		if (yearDigits >= _year && monthDigits >= _month && dayDigits >= _day) {
			std::cout << prevYear << "-" << prevMonth << "-" << prevDay << " => " << _btcCount << " = " << _btcCount * stringIntoFloat(dbValue) << std::endl;
			return ;
		}

		// (void)prevYear;
		// (void)prevMonth;
		// (void)prevDay;

		prevYear = yearDigits;
		prevMonth = monthDigits;
		prevDay = dayDigits;
	}

}




bool BitcoinExchange::lineFormatError(std::string& key, std::string& value) const {

	if (key.empty() || value.empty()) {
		std::cout << "Error: bad format." << std::endl;
		return true;
	}
	return false;
}

bool BitcoinExchange::dateFormatError(std::string dateStr) {
	
	std::string		yearStr, monthStr, dayStr;
	size_t			delPos;


	// if (dateStr.back() != ' ') {
	// 	std::cout << "Error: bad format." << std::endl;
	// 	return true;
	// }

	dateStr.pop_back();

	delPos = dateStr.find('-');
	yearStr = (delPos != std::string::npos) ? dateStr.substr(0, delPos) : "";
	size_t tmp = delPos + 1;
	delPos = dateStr.find('-', tmp);
	monthStr = (delPos != std::string::npos) ? dateStr.substr(tmp, delPos - tmp) : ""; 
	dayStr = (delPos != std::string::npos) ? dateStr.substr(delPos +  1) : ""; 

	// std::cout << "[" << yearStr << "]" << std::endl;
	// std::cout << "[" << monthStr << "]" << std::endl;
	// std::cout << "[" << dayStr << "]" << std::endl;

	// yearStr = removeFrontAndTraillingWhiteSpaces(yearStr);
	// monthStr = removeFrontAndTraillingWhiteSpaces(monthStr);
	// dayStr = removeFrontAndTraillingWhiteSpaces(dayStr);

	// std::cout << "[" << yearStr << "]" << std::endl;
	// std::cout << "[" << monthStr << "]" << std::endl;
	// std::cout << "[" << dayStr << "]" << std::endl;

	if (yearStr.empty() || monthStr.empty() || dayStr.empty()) {

		std::cout << "Error: bad input => " << dateStr << "." << std::endl;
		return true;	
	}

	if (!valueIsOnlyDigits(yearStr) || !valueIsOnlyDigits(monthStr) || !valueIsOnlyDigits(dayStr)) {

		std::cout << "Error: bad input => " << dateStr << "." << std::endl;
		return true;
	}

	if (nonExistentDateError(dateStr, yearStr, monthStr, dayStr))
		return true;	

	return false;
}

bool BitcoinExchange::valueFormatError(const std::string& valueStr) {

	// std::cout << "valueStr [" << valueStr << "]" << std::endl;
	
	std::string val = "";
	// std::cout << "val [" << val << "]" << std::endl;

	if (valueStr[0] == ' ')
		val = valueStr.substr(1);

		// std::cout << "HERE" << std::endl;
	if (strValFormatError(val)) {
		std::cout << "-> Error: bad format." << std::endl;
		return true;
	}
	
	


	if (!isFloat(val)) {
		std::cout << "Error: bad format." << std::endl;
		return true;
	}

	if (!intMaxIntMinInrangeCheck(stringIntoLong(val))) {
		std::cout << "Error: too large a number." << std::endl;
		return true;
	}


	// std::string truncValue = removeFrontAndTraillingWhiteSpaces(val);

	if (!isFloat(val)) {
		std::cout << "Error: bad input => " << val << "." << std::endl;
		return true;
	}

	_btcCount = stringIntoFloat(val);
	
	if (_btcCount < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return true;
	}
	return false;
}


/* -------- UTILS --------*/

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

bool BitcoinExchange::nonExistentDateError(const std::string& dateStr, const std::string& yearStr, const std::string& monthStr, const std::string& dayStr) {

	_year = stringIntoLong(yearStr);
	_month = stringIntoLong(monthStr);
	_day = stringIntoLong(dayStr);

	if (monthStr.size() > 2 || dayStr.size() > 2) {
		std::cout << "Error: bad input => " << dateStr << "." << std::endl;
		return true;	
	}

	if (!intMaxIntMinInrangeCheck(_year) || !intMaxIntMinInrangeCheck(_month) || !intMaxIntMinInrangeCheck(_day)) {
			std::cout << "Error: too large a number." << std::endl;
			return true;
	}

	if (_month < 1 || _month > 12) {
		std::cout << "Error: bad input => " << dateStr << "." << std::endl;
		return true;
	}
		
	if (_day < 1 || ((_month % 2) && _day > 31) ||
		(!(_month % 2) && _day > 30) || ((_month == 2) && _day > 28)) {
			std::cout << "Error: bad input => " << dateStr << "." << std::endl;
			return true;
	}
	return false;
}

bool BitcoinExchange::strValFormatError(std::string& str) const {

	size_t multipleDotCount = 0;

	for (size_t i = 0; i < str.length(); ++i) {

		if (str[i] == '.')
			multipleDotCount++;
		if ((str[0] != '-' && !std::isdigit(str[i]) && str[i] != '.') || multipleDotCount == 2)
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

	if (*end != '\0')
		return -1.0;

	return static_cast<float>(result);
}

long BitcoinExchange::stringIntoLong(const std::string& str) const {

    char* end;
    const char* cstr = str.c_str();
    long result = std::strtol(cstr, &end, 10);

    if (*end != '\0')
        return -1;

    return result;
}

bool BitcoinExchange::intMaxIntMinInrangeCheck(long nb) const {

	return (nb < std::numeric_limits<int>::max() && nb > std::numeric_limits<int>::min());
}
