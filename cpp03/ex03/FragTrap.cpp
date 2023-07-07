/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:53:10 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/29 14:37:12 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap created!" << std::endl;
	this->_energy = 100;
	this->_hp = 100;
	this->_attackDamage = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap created!" << std::endl;
	this->_name = name;
	this->_energy = 100;
	this->_hp = 100;
	this->_attackDamage = 100;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " destroyed!" << std::endl;
}

void FragTrap::highFiveGuys() {
	std::cout << "Give me a high five Maaaan!" << std::endl;
}