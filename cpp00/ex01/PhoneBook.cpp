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

void	PhoneBook::add_contact(Contact contact)
{
	for (int8_t i = 7; i >= 0; i--)
		this->contact[i] = this->contact[i - 1];
	this->contact[0] = contact;
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

bool	PhoneBook::contact_index_error(std::string index_str)
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
	while (!this->contact[max_index].name.empty())
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

void	PhoneBook::look_for_contact_info()
{
	std::string		input;
	std::string		tmp;
	short			_space_count;
	short			index;

	std::cout << "HERE"<< this->contact[0].name << std::endl;


	std::cout << "Enter the contact index you're looking for!" << std::endl;
	std::getline(std::cin, input);
	if (contact_index_error(input))
	{
		std::cout << "Wrong Input" << std::endl;
		return;
	}
	index = std::stoi(input);
	std::cout << "|";
	print_content(input);
	std::cout << "|";
	print_content(this->contact[index].name);
	std::cout << "|";
	print_content(this->contact[index].last_name);
	std::cout << "|";
	print_content(this->contact[index].nickname);
	std::cout << "|" << std::endl;
}
