/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:01 by caboudar          #+#    #+#             */
/*   Updated: 2023/07/25 16:22:20 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <stdint.h>
#include <cstdlib>
#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

void	Contact::create_contact()
{
	std::string		input;

	while (input.empty())
	{
		std::cout << "Insert your first name:" << std::endl;
		std::getline(std::cin, input);
		this->_firstName = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert your last name:" << std::endl;
		std::getline(std::cin, input);
		this->_lastName = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert a nickname name:" << std::endl;
		std::getline(std::cin, input);
		this->_nickName = input;
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
				std::cout << "Please insert digits only" << std::endl << std::endl;
				input.clear();
				break;
			}
		}
		this->_phoneNumber = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert your darkest secret:" << std::endl;
		std::getline(std::cin, input);
		this->_darkestSecret = input;
	}
}

std::string		Contact::getFirstName() const { return this->_firstName; }
std::string		Contact::getLastName() const { return this->_lastName; }
std::string		Contact::getNickName() const { return this->_nickName; }
std::string		Contact::getPhoneNumber() const { return this->_phoneNumber; }
std::string		Contact::getDarketSecret() const { return this->_darkestSecret; }
