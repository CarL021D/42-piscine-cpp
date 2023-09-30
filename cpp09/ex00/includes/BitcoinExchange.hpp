#include <iostream>
#include <map>
#include <fstream>
#include <string>

class BitcoinExchange {
	public:
			BitcoinExchange();
			~BitcoinExchange();
			BitcoinExchange(std::ifstream infile);
			BitcoinExchange(const BitcoinExchange& src);
			BitcoinExchange& operator=(const BitcoinExchange& rhs);

			bool	checkValidFormatFile(char *inFile);
			void	displayBtcStockExchangePrice(char *btcDB, char *inFile);
	private:
			std::map<std::string, std::string> _data;
};
