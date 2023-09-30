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
			&BitcoinExchange operator=(const BitcoinExchange& rhs);

			void storeFileContent(char *inFile) {

			void	displayBtcPrice();
	private:
			std::map<std::string, std:string> _data;
}