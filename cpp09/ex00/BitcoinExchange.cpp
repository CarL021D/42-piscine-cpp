#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
 	
	_btcDBMap.insert(src._btcDBMap.begin(), src._btcDBMap.end());
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	 
 	_btcDBMap.insert(rhs._btcDBMap.begin(), rhs._btcDBMap.end());
	 return *this;
}

void BitcoinExchange::fillBtcDBmap(std::ifstream& btcDB) {

	std::string line;

	std::getline(btcDB, line);

	while (std::getline(btcDB, line)) {
				
		size_t delPos = line.find(',');

		std::string date = (delPos != std::string::npos) ? line.substr(0, delPos) : line;
		std::string value = (delPos != std::string::npos) ? line.substr(delPos + 1) : "";
		
		_btcDBMap.insert(std::pair<std::string,std::string>(date, value));
	}
}

void BitcoinExchange::displayBtcStockExchangeRate(std::ifstream& inFile) {
	
	std::string line;
	
	while (std::getline(inFile, line)) {
		size_t delPos = line.find('|');

		std::string date = (delPos != std::string::npos) ? line.substr(0, delPos) : line;
		std::string value = (delPos != std::string::npos) ? line.substr(delPos + 1) : "";

		if (!(dateFormatError(date) || lineFormatError(date, value) || valueFormatError(value)))
			displayBtcValue(date, value);
	}
}

void	BitcoinExchange::displayBtcValue(std::string& date, std::string& value) {

	date = removeFrontAndTraillingWhiteSpaces(date);
	value = removeFrontAndTraillingWhiteSpaces(value);

	std::map<std::string, std::string>::iterator it = _btcDBMap.find(date);	
	if (it != _btcDBMap.end())
		std::cout << date << " => " << value << " = " << stringIntoFloat(value) * stringIntoFloat(_btcDBMap[date]) << std::endl;
	else {

		_btcDBMap.insert(std::make_pair(date, ""));
		it = _btcDBMap.find(date);
		--it;
		std::cout << date << " => " << value << " = " << stringIntoFloat(value) * stringIntoFloat(it->second) << std::endl;
		++it;
		_btcDBMap.erase(it);
	}
}

bool BitcoinExchange::lineFormatError(const std::string& key, const std::string& value) const {

	if (key.empty() || value.empty()) {
		std::cout << "Error: bad format." << std::endl;
		return true;
	}
	return false;
}

bool BitcoinExchange::dateFormatError(std::string dateStr) {
	
	std::string		yearStr, monthStr, dayStr;
	size_t			delPos;

	if (dateStr[dateStr.length() - 1] == ' ')
		dateStr.resize(dateStr.length() - 1);

	delPos = dateStr.find('-');
	yearStr = (delPos != std::string::npos) ? dateStr.substr(0, delPos) : "";
	size_t tmp = delPos + 1;
	delPos = dateStr.find('-', tmp);
	monthStr = (delPos != std::string::npos) ? dateStr.substr(tmp, delPos - tmp) : ""; 
	dayStr = (delPos != std::string::npos) ? dateStr.substr(delPos + 1) : ""; 

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

	std::string val = "";

	if (valueStr[0] == ' ')
		val = valueStr.substr(1);

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
			truncStr = truncStr.substr(0, endPos + 1 );
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
		
	if ((_month < 1 || _month > 12) || _day < 1 || ((_month % 2) && _day > 31) ||
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

	return static_cast<float>(result);
}

int64_t BitcoinExchange::stringIntoLong(const std::string& str) const {

    char* end;
    const char* cstr = str.c_str();
    long result = std::strtol(cstr, &end, 10);

    return result;
}

bool BitcoinExchange::intMaxIntMinInrangeCheck(long nb) const {

	return (nb < std::numeric_limits<int>::max() && nb > std::numeric_limits<int>::min());
}
