/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:15:40 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/17 17:07:43 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	
	funcArr[0].level = "DEBUG";
	funcArr[0].funcPtr = &Harl::_debug;
	funcArr[1].level = "INFO";
	funcArr[1].funcPtr = &Harl::_info;
	funcArr[2].level = "WARNING";
	funcArr[2].funcPtr = &Harl::_warning;
	funcArr[3].level = "ERROR";
	funcArr[3].funcPtr = &Harl::_error;

}
Harl::~Harl() {}

void	Harl::complain(std::string level) {
	
	int i = 0;
	
	while (i < 4 && funcArr[i].level != level) { i++; }
		
	switch (i)
	{
		case 0:
			(this->*funcArr[0].funcPtr)();
		case 1:
			(this->*funcArr[1].funcPtr)();
		case 2:
			(this->*funcArr[2].funcPtr)();
		case 3:
			(this->*funcArr[3].funcPtr)();
		default:
			std::cout << "Probably complaining about insignificant problems." << std::endl;
	}
}

void	Harl::_debug() {
	std::cout << "I love extra bacon." << std::endl;
}

void	Harl::_info() {
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
}

void	Harl::_warning() {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void	Harl::_error() {
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
