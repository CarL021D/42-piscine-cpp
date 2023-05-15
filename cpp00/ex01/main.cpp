/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:09 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:42:10 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
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
		}
		else if (input == "SEARCH")
			phoneBook.look_for_contact_info();
		else if (input == "EXIT")
			return 0;
	}
}