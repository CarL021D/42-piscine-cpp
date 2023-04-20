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
	for (int8_t i = 7; i > 0; i--)
		this->contact[i] = this->contact[i - 1];
	this->contact[0] = contact;
}

short	PhoneBook::space_count(std::string str)
{
	if (str.length() >= 10)
		return 0;
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

bool	PhoneBook::contact_index_error(std::string input)
{
	short			max_index;
	long long		int_input;

	if (input.empty())
		return true;
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			std::cout << "Unknown characters, insert digits only!" << std::endl;
			return true;
		}
	}
	// max_index = 0;
	// // TODO: - Error max_index incrementation bugged
	// while (!this->contact[max_index].name.empty())
	// 	max_index++;
	
	// if (!max_index)
	// {
	// 	std::cout << "Phone book empty" << std::endl;
	// 	return true;
	// }
	int_input = std::stoi(input);
	if ((int_input < 0 || int_input > 7) || contact[int_input].first_name.empty())
	{
		std::cout << "Wrong input!" << std::endl;
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

void	PhoneBook::display_contacts_info()
{
	std::cout << std::endl << "|";
	for (short i = 0; i < 5; i++)
		std::cout << " ";
	std::cout << "index|";
	for (short i = 0; i < 1; i++)
		std::cout << " ";
	std::cout << "firstName|";
	for (short i = 0; i < 2; i++)
		std::cout << " ";
	std::cout << "lastName|";
	for (short i = 0; i < 2; i++)
		std::cout << " ";
	std::cout << "nickname|" << std::endl;
	for (short i = 0; i < 8; i++)
	{
		std::cout << "|         " << i << "|";		
		print_content(contact[i].first_name);
		std::cout << "|";
		print_content(contact[i].last_name);
		std::cout << "|";
		print_content(contact[i].nickname);
		std::cout << "|" << std::endl;
	}
		std::cout << std::endl;
}

void	PhoneBook::single_contact_info_display(std::string input)
{
	int32_t index = std::stoi(input);

	std::cout << std::endl << "first name: " << contact[index].first_name << std::endl;
	std::cout << "last name: " << contact[index].last_name << std::endl;
	std::cout << "nickname: " << contact[index].nickname << std::endl;
	std::cout << "phone number: " << contact[index].phone_number << std::endl;
	std::cout << "darkest secret: " << contact[index].darkest_secret << std::endl << std::endl;

}

void	PhoneBook::look_for_contact_info()
{
	std::string		input;

	display_contacts_info();
	std::cout << "Enter the contact's index you're looking for!" << std::endl;
	std::getline(std::cin, input);
	if (contact_index_error(input))
		return ;
	single_contact_info_display(input);
	// index = std::stoi(input);
	
	// for (short i = 0; i < 7; i++)
	// {
	// 	std::cout << "|";



	// }
	// print_content(input);
	// std::cout << "|";
}
