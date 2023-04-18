#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdint>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) {
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

PhoneBook		PhoneBook::add_contact(PhoneBook phoneB, Contact contact)
{
	int8_t	i = 7;

	while (i >= 0)
	{
		phoneB.contact[i - 1] = phoneB.contact[i];
		i--;
	}
	phoneB.contact[0] = contact;
	return phoneB;
}

short	PhoneBook::space_count(std::string str)
{
	return (10 - str.length());
}

std::string	PhoneBook::truncate_str(std::string str)
{
	std::string		ret;

	if (str.length() <= 10)
		return str;
	ret = str.substr(0, 9);
	ret.push_back('.');
	return ret;
}

bool	PhoneBook::contact_index_error(PhoneBook phoneB, std::string index_str)
{
	unsigned short	max_index;
	long long		value;

	if (index_str.empty())
		return true;
	for (unsigned int i = 0; i < index_str.length(); i++)
	{
		if (!isdigit(index_str[i]))
		{
			std::cout << "Unknown characters, insert digits only!" << std::endl;
			return true;
		}
	}
	max_index = 0;
	while (!phoneB.contact[max_index].name.empty())
		max_index++;
	value = std::stoi(index_str);
	if (value < 0 || value < max_index)
	{
		std::cout << "Error, chose an index between 0 and " << max_index << std::endl;
		return true;
	}
	return false;
}

void	PhoneBook::print_content(std::string input)
{
	std::string		_truncate_str;
	short			_space_count;

	_space_count = space_count(input);
	while (_space_count)
	{
		std::cout << " ";
		_space_count--;
	}
	_truncate_str = truncate_str(input);
	std::cout << _truncate_str;
}

void	PhoneBook::look_for_contact_info(PhoneBook phoneB)
{
	std::string		input;
	std::string		tmp;
	short			_space_count;
	short			index;

	std::cout << "Enter the contact index you're looking for!" << std::endl;
	std::getline(std::cin, input);
	if (contact_index_error(phoneB, input))
	{
		std::cout << "Wrong Input" << std::endl;
		return;
	}
	index = std::stoi(input);
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
