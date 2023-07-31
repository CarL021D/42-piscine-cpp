/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:49:35 by caboudar          #+#    #+#             */
/*   Updated: 2023/07/31 13:24:22 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap created!" << std::endl;
	this->_name = "DefaultScavName";
	this->_energy = 50;
	this->_hp = 100;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
	std::cout << "ScavTrap created!" << std::endl;
	this->_name = name;
	this->_energy = 50;
	this->_hp = 100;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) { *this = src; }

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	this->_name = rhs._name;
	this->_energy = rhs._energy;
	this->_hp = rhs._hp;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void ScavTrap::guardGate() { std::cout << "Guard gate mode activated" << std::endl; }

void ScavTrap::attack(const std::string& target) {
	
	if (this->_energy == 0) {
		std::cout << std::endl << this->_name <<  " couldn't attack, he has no energy left" << std::endl << std::endl;	
		return ;
	}
	this->_energy -= 1;
	std::cout << this->_name << " punched in the face " << target << " dealing " << this->_attackDamage << " damage(s)" << std::endl;
	std::cout << this->_name << " has " << this->_energy << " energy left" << std::endl;	
}
