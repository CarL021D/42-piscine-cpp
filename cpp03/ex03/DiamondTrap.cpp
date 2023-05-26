/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:03:10 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/24 17:54:50 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name) , ScavTrap(name) {
	std::cout << "DiamondTrap created!" << std::endl;
	this->_name  = name + "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_energy = ScavTrap::_energy;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " destroyed!" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->_name << " son of " << ClapTrap::_name << std::endl;
}
