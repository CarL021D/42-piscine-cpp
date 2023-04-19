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
		std::cout << "Enter a command!" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			new_contact.create_contact();
			phoneBook.add_contact(new_contact);
			// std::cout << "1: " << phoneBook.contact[0].name << std::endl;
			// std::cout << "2: " << phoneBook.contact[1].name << std::endl;
		}
		else if (input == "SEARCH")
			phoneBook.look_for_contact_info();
		else if (input == "EXIT")
			return 0;
	}

	// phoneBook.contact[0].name = str;
	// char str[] = "Carl";
	// std::cout << phoneBook.contact[0].name << std::endl;
}