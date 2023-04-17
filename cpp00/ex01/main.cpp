#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int ac, char **av)
{
	PhoneBook		phoneBook;
	Contact			new_contact;
	std::string		input;
	
	while (1)
	{
		std::cout << "Enter a command !" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			new_contact = Contact::create_contact();
			phoneBook.add_contact(phoneBook, new_contact);
		}
		else if (input == "SEARCH")
			std::cout << "SEARCH" << std::endl;
		else if (input == "EXIT")
		{
			std::cout << "EXIT" << std::endl;
			return 0;
		}
	}

	// phoneBook.contact[0].name = str;
	// char str[] = "Carl";
	// std::cout << phoneBook.contact[0].name << std::endl;
}