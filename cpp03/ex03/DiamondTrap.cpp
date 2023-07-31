/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:03:10 by caboudar          #+#    #+#             */
/*   Updated: 2023/07/31 13:24:43 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DefaultDiamondName_clap_name") {
	std::cout << "DiamondTrap created!" << std::endl;
	this->_name  = "DefaultDiamondName";
	this->_hp = FragTrap::_hp;
	this->_energy = ScavTrap::_energy;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
	std::cout << "DiamondTrap created!" << std::endl;
	this->_name  = name;
	this->_hp = FragTrap::_hp;
	this->_energy = ScavTrap::_energy;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) { *this = src; }

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	this->_name = rhs._name;
	this->_energy = rhs._energy;
	this->_hp = rhs._hp;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->_name << " son of " << ClapTrap::_name << std::endl;
}
