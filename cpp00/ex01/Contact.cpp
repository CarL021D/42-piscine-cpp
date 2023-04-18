#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

Contact		Contact::create_contact()
{
	Contact			contact;
	std::string		input;

	while (input.empty())
	{
		std::cout << "Insert your first name:" << std::endl;
		std::getline(std::cin, input);
		contact.name = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert your last name:" << std::endl;
		std::getline(std::cin, input);
		contact.last_name = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert a nickname name:" << std::endl;
		std::getline(std::cin, input);
		contact.nickname = input;
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
		contact.phone_number = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert darkest secret:" << std::endl;
		std::getline(std::cin, input);
		contact.darkest_secret = input;
	}
	std::cout << contact.name << std::endl;
	std::cout << contact.last_name << std::endl;
	std::cout << contact.nickname << std::endl;

	return contact;
}

unsigned short	dot_count(std::str str)
{
	unsigned int	len;

	len = strlen(str);
	return (10 - len);


	// short			dot_count = 0;
	// char			temp;

	// len = strlen(str);
	// if (len > 10)
	// 	len = 9;
	// if (len < 10)
	// 	dot_count = 10 - len;
	// temp = str.substr(0, )
}

std::str	PhoneBook::truncate_str(std::str str)
{
	unsigned int	len;
	std::str		ret;

	len = strlen(str);
	if (len <= 10)
		return str;
	ret = str.substr(0, 9);
	return ret;
}

void	PhoneBook::display_contact_info(PhoneBook phoneB)
{
	std::string		input;


	std::cout << "Enter the contact you are looking for!" << std::endl;
	std::getline(std::cin, input);
	while (i < 8)
	{
		if (input == phoneB.contact[i].name)
		{
			len = strlen(input);
			if (len > 9)
				len = 9;
			if 

		}
	}

}