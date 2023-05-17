/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:15:40 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/17 15:48:22 by caboudar         ###   ########.fr       */
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
		for (int i = 0; i < 4; i++)
		{
			if (level == funcArr[i].level)
			{
				(this->*funcArr[i].funcPtr)();
				return ;
			}
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
