#include <iostream>
#include <cstdlib>
#include <map>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdint>
#include <limits>

class BitcoinExchange {
	public:
			BitcoinExchange(void);
			~BitcoinExchange(void);
			BitcoinExchange(std::ifstream infile);
			BitcoinExchange(const BitcoinExchange& src);
			BitcoinExchange& operator=(const BitcoinExchange& rhs);

			bool	checkValidFileFormat(int ac, char *inFile);
			void	displayBtcStockExchangeRate(void);

	private:
			std::map<std::string, std::string> _data;
			std::ifstream _inFile;
			std::ifstream _btcDB;
			int64_t _year;
			int64_t _month;
			int64_t _day;
			float _btcCount;

			void displayBtcValue(void);
			bool lineFormatError(std::string& key, std::string& value) const;
			bool dateFormatError(std::string dateStr);
			bool valueFormatError(const std::string& valueStr);

			const std::string removeFrontAndTraillingWhiteSpaces(const std::string& str) const;
			bool valueIsOnlyDigits(const std::string& dateStr) const;
			bool nonExistentDateError(const std::string& dateStr, const std::string& yearStr, const std::string& monthStr, const std::string& dayStr);
			bool intMaxIntMinInrangeCheck(long nb) const;
			bool isFloat(const std::string &str) const;
			bool strValFormatError(std::string& str) const;
			int64_t stringIntoLong(const std::string& str) const;
			float stringIntoFloat(std::string& str) const;

};
