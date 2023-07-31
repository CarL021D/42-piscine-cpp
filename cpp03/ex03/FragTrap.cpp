/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:53:10 by caboudar          #+#    #+#             */
/*   Updated: 2023/07/31 13:25:08 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap created!" << std::endl;
	this->_energy = 100;
	this->_hp = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap created!" << std::endl;
	this->_name = name;
	this->_energy = 100;
	this->_hp = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) { *this = src; }

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	this->_name = rhs._name;
	this->_energy = rhs._energy;
	this->_hp = rhs._hp;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void FragTrap::highFiveGuys() {
	std::cout << "Give me a high five Maaaan!" << std::endl;
}