/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:01 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:42:02 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <stdint.h>
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
	std::string		input;

	while (input.empty())
	{
		std::cout << "Insert your first name:" << std::endl;
		std::getline(std::cin, input);
		first_name = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert your last name:" << std::endl;
		std::getline(std::cin, input);
		last_name = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert a nickname name:" << std::endl;
		std::getline(std::cin, input);
		nickname = input;
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
		phone_number = input;
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Insert your darkest secret:" << std::endl;
		std::getline(std::cin, input);
		darkest_secret = input;
	}
}
