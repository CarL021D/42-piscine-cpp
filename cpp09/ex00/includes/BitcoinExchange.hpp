#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>

class BitcoinExchange {
	public:
			BitcoinExchange();
			~BitcoinExchange();
			BitcoinExchange(std::ifstream infile);
			BitcoinExchange(const BitcoinExchange& src);
			BitcoinExchange& operator=(const BitcoinExchange& rhs);

			bool	checkValidFileFormat(int ac, char *inFile);
			void	displayBtcStockExchangeRate(char *btcDB, char *inFile);

	private:
			std::map<std::string, std::string> _data;
			float _val;

			const std::string removeFrontAndTraillingWhiteSpaces(const std::string& str);
			const bool lineFormatErrorCheck(std::string value);
			const bool	dateCheckError(std::string dateStr);
			const bool valueCheckError(std::string& value);

			const bool dateAintOnlyDigits(const std::string& dateStr);
			const bool wrongDateError(const std::string& dateStr, const std::string& year, const std::string& month, const std::string& day);
			const bool isFloat(const std::string &str);
};
