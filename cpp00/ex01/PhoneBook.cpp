/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:16 by caboudar          #+#    #+#             */
/*   Updated: 2023/07/25 13:26:00 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stdint.h>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) { return; }

PhoneBook::~PhoneBook(void) { return; }

void	PhoneBook::add_contact(Contact contact)
{
	for (int8_t i = 7; i > 0; i--)
		this->_contact[i] = this->_contact[i - 1];
	this->_contact[0] = contact;
}

short	PhoneBook::space_count(std::string str) const
{
	if (str.length() >= 10)
		return 0;
	return (10 - str.length());
}

std::string	PhoneBook::truncate_str(std::string str) const
{
	std::string		ret;

	if (str.length() <= 10)
		return str;
	ret = str.substr(0, 9);
	ret.push_back('.');
	return ret;
}

bool	PhoneBook::contact_index_error(std::string input) const
{
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
	int_input = std::atoi(input.c_str());
	if ((int_input < 0 || int_input > 7) || _contact[int_input].first_name.empty())
	{
		std::cout << "Wrong input!" << std::endl;
		return true;
	}
	return false;
}

void	PhoneBook::print_content(std::string input) const
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

void	PhoneBook::display_contacts_info() const
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
		print_content(_contact[i].first_name);
		std::cout << "|";
		print_content(_contact[i].last_name);
		std::cout << "|";
		print_content(_contact[i].nickname);
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::single_contact_info_display(std::string input) const
{
	int32_t index = std::atoi(input.c_str());

	std::cout << std::endl << "first name: " << _contact[index].first_name << std::endl;
	std::cout << "last name: " << _contact[index].last_name << std::endl;
	std::cout << "nickname: " << _contact[index].nickname << std::endl;
	std::cout << "phone number: " << _contact[index].phone_number << std::endl;
	std::cout << "darkest secret: " << _contact[index].darkest_secret << std::endl << std::endl;

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
}
