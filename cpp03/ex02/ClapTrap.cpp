/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:49:35 by caboudar          #+#    #+#             */
/*   Updated: 2023/08/02 12:01:37 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap created!" << std::endl;
	this->_name = "DefaultClapName";
	this->_energy = 10;
	this->_hp = 10;
	this->_attackDamage = 0;	
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap created!" << std::endl;
	this->_name = name;
	this->_energy = 10;
	this->_hp = 10;
	this->_attackDamage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) { *this = src; }

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	this->_name = rhs._name;
	this->_energy = rhs._energy;
	this->_hp = rhs._hp;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	
	if (this->_energy == 0) {
		std::cout << std::endl << this->_name <<  " couldn't attack, he has no energy left" << std::endl << std::endl;	
		return ;
	}
	this->_energy -= 1;
	std::cout << this->_name << " attacked " << target << " dealing " << this->_attackDamage << " damage(s)" << std::endl;
	std::cout << this->_name << " has " << this->_energy << " energy left" << std::endl;
	
}


void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp == 0)
	{
		std::cout << this->_name << " didn't take any damage(s), he's alredy dead" << std::endl << std::endl; 		
		return ;	
	}
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " damage(s)" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has " << this->_hp << " hp remaining" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy == 0)
	{
		std::cout << this->_name << "has not enough energy to repaidred itself" << std::endl;
		return ;
	}
	this->_energy -= 1;
	this->_hp += amount;
	std::cout << std::endl << this->_name << " healed himself for " << amount << " hp(s)" << std::endl;
	std::cout << this->_name << " has " <<  this->_hp << " hp(s)" << std::endl;
	std::cout << this->_name << " has " << this->_energy << " energy left" << std::endl << std::endl;
}

unsigned int ClapTrap::getDamage() { return this->_attackDamage; }