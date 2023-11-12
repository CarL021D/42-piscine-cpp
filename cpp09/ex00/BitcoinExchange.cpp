#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {

	// if (_inFile.is_open())
	// 	_inFile.close();
	//  if (_btcDB.is_open())
	// 	_btcDB.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) { *this = src; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	 
	 (void)rhs;
	 return *this;
}

// bool BitcoinExchange::checkValidFileFormat(int ac, char *inFile) {

// 	std::ifstream _inFile, btcDB;

// 	std::string 	line;

// 	if (ac != 2) {
// 		std::cout << "Error: wrong number of arguments" << std::endl;
// 		return false;
// 	}

// 	inFile.open(inFile);
// 	btcDB.open("data.csv");

// 	if (!inFile.is_open() || !btcDB.is_open()) {
// 		std::string str(inFile);

// 		std::cerr << "Error: could not open file." << std::endl;
// 		return false; 
// 	}

// 	if (std::getline(inFile, line)) {
// 		if (line != "date | value") {
// 			std::cerr << "Error: - wrong file format." << std::endl;
// 			return false;
// 		}
// 	}
// 	return true;
// }

void BitcoinExchange::fillBtcDBmap(std::ifstream& btcDB) {

	// std::ifstream btcDB;
	std::string line;

	// btcDB.open("data.csv");

	std::getline(btcDB, line);

	while (std::getline(btcDB, line)) {
				
		size_t delPos = line.find(',');

		std::string date = (delPos != std::string::npos) ? line.substr(0, delPos) : line;
		std::string value = (delPos != std::string::npos) ? line.substr(delPos + 1) : "";
		
		// std::cout << "		date - [" << date << "]" << std::endl;
		// std::cout << "		value - [" << value << "]" << std::endl;


		_btcDBMap.insert(std::pair<std::string,std::string>(date, value));

	}
	btcDB.close();
}

void BitcoinExchange::displayBtcStockExchangeRate(std::ifstream& inFile) {
	
	// std::ifstream inFile, btcDB;
	std::string line;
	
	// inFile.open(fileName);
	// btcDB.open("data.csv");



	
	// std::getline(inFile, line);

	while (std::getline(inFile, line)) {
		size_t delPos = line.find('|');

		std::string date = (delPos != std::string::npos) ? line.substr(0, delPos) : line;
		std::string value = (delPos != std::string::npos) ? line.substr(delPos + 1) : "";

		// if (date.size())
		// 	date.erase(date.size() - 1);
		
		// std::cout << "		date - [" << date << "]" << std::endl;
		// std::cout << "		value - [" << value << "]" << std::endl;
		// value.erase(0, 1);
		
		// std::cout << "		value - [" << value << "]" << std::endl;

		// _data.insert(std::pair<std::string,std::string>(key, value));
	
		// for (std::map<std::string, std::string>::const_iterator it = _data.begin(); it != _data.end();) {

			if (!(dateFormatError(date) || lineFormatError(date, value) || valueFormatError(value)))
				displayBtcValue(date, value);
		// 	break ;
		// }
		// _data.erase(_data.begin());
	}
	// btcDB.close();
}

void	BitcoinExchange::displayBtcValue(std::string& date, std::string& value) {

	if (date.size())
		date.erase(date.size() - 1);
	value.erase(0, 1);

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
	// std::string line, dbYear, dbMonth, dbDay;
	// long yearDigits, monthDigits, dayDigits, prevYear, prevMonth, prevDay;

	// _btcDB.seekg(0, std::ios::beg);
	// std::getline(_btcDB, line);

	// while (std::getline(_btcDB, line)) {
		
	// 	size_t delPos = line.find(',');
	// 	std::string dbDate = (delPos != std::string::npos) ? line.substr(0, delPos) : line;
	// 	std::string dbValue = (delPos != std::string::npos) ? line.substr(delPos + 1) : "";

	// 	delPos = dbDate.find('-');
	// 	dbYear = dbDate.substr(0, delPos);
	// 	size_t tmp = delPos + 1;
	// 	delPos = dbDate.find('-', tmp);
	// 	dbMonth = dbDate.substr(tmp, delPos - tmp); 
	// 	dbDay = dbDate.substr(delPos +  1); 

	// 	yearDigits = stringIntoFloat(dbYear);
	// 	monthDigits = stringIntoFloat(dbMonth);
	// 	dayDigits = stringIntoFloat(dbDay);

	// 	//TODO: - Check if the date precede min creation

	// 	if (yearDigits == _year && monthDigits == _month && dayDigits == _day) {
	// 		std::cout << _year << "-" << _month << "-" << _day << " => " << _btcCount << " = " << _btcCount * stringIntoFloat(dbValue) << std::endl;
	// 		return ;
	// 	}
		
	// 	if (yearDigits >= _year && monthDigits >= _month && dayDigits >= _day) {
	// 		std::cout << prevYear << "-" << prevMonth << "-" << prevDay << " => " << _btcCount << " = " << _btcCount * stringIntoFloat(dbValue) << std::endl;
	// 		return ;
	// 	}

	// 	prevYear = yearDigits;
	// 	prevMonth = monthDigits;
	// 	prevDay = dayDigits;
	// }
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

	if (*end != '\0')
		return -1.0;

	return static_cast<float>(result);
}

int64_t BitcoinExchange::stringIntoLong(const std::string& str) const {

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
