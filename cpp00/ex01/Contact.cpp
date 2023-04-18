#include <iostream>
#include <cstdlib>
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

unsigned short	space_count(std::str str)
{
	unsigned int	len;

	len = strlen(str);
	return (10 - len);
}

std::str	PhoneBook::truncate_str(std::str str)
{
	unsigned int	len;
	std::str		ret;

	len = strlen(str);
	if (len <= 10)
		return str;
	ret = str.substr(0, 9);
	ret.push_back('.');
	return ret;
}

bool	contact_index_error(PhoneBook phoneB, std::str index_str)
{
	unsigned short	len;
	unsigned short	max_index;
	long long		value;

	if (index.empy)
		return true;
	len = strlen(index_str)
	for (unsigned int i; i < len; i++)
	{
		if (!index_str.isdigit())
			std::cout << "Unknonw characters, inset digits only" << std::stdl;
		return true;
	}
	max_index = 0;
	while (!phoneB.contact[max_index].name.empty())
		max_index++;
	value = atoi(index);
	if (value < 0 || value < max_index)
	{
		std::cout << "Error, chose an index between 0 and " << max_index << std::stdl;
		return true;
	}
	return false;
}

void	print_content(std::str input)
{
	std::str	_truncate_str;
	short		_space_count;

	_space_count = space_count(input);
	while (_space_count)
	{
		std::cout << " ";
		_space_count--;
	}
	_truncate_str = truncate_str(unput);
	std::cout << _truncate_str;
}

void	PhoneBook::display_contact_info(PhoneBook phoneB)
{
	std::string		input;
	std::string		tmp;
	short	_space_count;
	short	index;

	while (contact_index_error(phoneB, input))
	{
		input.clear();
		std::cout << "Enter the contact index you're looking for!" << std::endl;
		std::getline(std::cin, input);
	}
	index = atoi(input);
	std::cout << "|";
	print_content(input);
	std::cout << "|";
	print_content(phoneB.contact[index].name);
	std::cout << "|";
	print_content(phoneB.contact[index].last_name);
	std::cout << "|";
	print_content(phoneB.contact[index].nickname);
	std::cout << "|" << std::endl;
	
}