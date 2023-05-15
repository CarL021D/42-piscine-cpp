/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:15:40 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 21:52:24 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void	Harl::complain(std::string level) {
	
	void	(*funcArr[4])(void);

	funcArr[0] = &debug;
	funcArr[1] = &info;
	funcArr[2] = &warning;
	funcArr[3] = &error;
	
}

void	Harl::_debug() {
	std::cout << "" << std::endl;
}

void	Harl::_info() {
	std::cout << "" << std::endl;
}

void	Harl::_warning() {
	std::cout << "" << std::endl;
}

void	Harl::_error() {
	std::cout << "" << std::endl;
}
