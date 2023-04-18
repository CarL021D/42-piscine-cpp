#include <iostream>
#include <cstdlib>
#include "Contact.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

void		Contact::create_contact()
{
	// Contact			contact;
	std::string		input;

	while (input.empty())
	{
		std::cout << "Insert your first name:" << std::endl;
		std::getline(std::cin, input);
		this->name = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert your last name:" << std::endl;
		std::getline(std::cin, input);
		this->last_name = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert a nickname name:" << std::endl;
		std::getline(std::cin, input);
		this->nickname = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert a phone number:" << std::endl;
		std::getline(std::cin, input);
		for (unsigned int i = 0; input[i]; i++)
		{
			if (!isdigit(input[i]))
			{
				std::cout << "Insert digits only" << std::endl;
				input.clear();
			}
			break;
		}
		this->phone_number = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert your darkest secret:" << std::endl;
		std::getline(std::cin, input);
		this->darkest_secret = input;
	}
	// std::cout << contact.name << std::endl;
	// std::cout << contact.last_name << std::endl;
	// std::cout << contact.nickname << std::endl;
}
