#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int ac, char **av)
{
	PhoneBook	phoneBook;
	// std::string input;
	
	// while (1)
	// {
	// 	std::getline(std::cin, input);
	// 	if (input == "ADD")

	// 	else if (input == "SEARCH")

	// 	else if (input == "EXIT")
	// 		return 0;
	// }

	char str[] = "Carl";
	phoneBook.contact[0].name = str;
	std::cout << phoneBook.contact[0].name << std::endl;
}