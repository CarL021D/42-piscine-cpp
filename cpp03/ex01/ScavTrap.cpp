/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:49:35 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/22 21:37:03 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
	std::cout << "ScavTrap created!" << std::endl;
	this->_name = name;
	this->_energy = 50;
	this->_hp = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destroyed!" << std::endl;
}

// void ScavTrap::setDamage(unsigned int amount) { this->_attackDamage = amount; }

// void ScavTrap::attack(const std::string& target) {
	
// 	if (this->_energy == 0) {
// 		std::cout << std::endl << this->_name <<  " couldn't attack, he has no energy left" << std::endl << std::endl;	
// 		return ;
// 	}
// 	this->_energy -= 1;
// 	std::cout << this->_name << " attacked " << target << " dealing " << this->_attackDamage << " damage(s)" << std::endl;
// 	std::cout << this->_name << " has " << this->_energy << " energy left" << std::endl;
	
// }

// void ScavTrap::takeDamage(unsigned int amount) {
// 	if (this->_hp <= 0)
// 	{
// 		this->_hp = 0;
// 		std::cout << this->_name << " didn't take any damage(s), he's alredy dead" << std::endl << std::endl; 		
// 		return ;	
// 	}
// 	this->_hp -= amount;
// 	std::cout << "ScavTrap " << this->_name << " took " << amount << " damage(s)" << std::endl;
// 	std::cout << "ScavTrap " << this->_name << " has " << this->_hp << " hp remaining" << std::endl;
// }

// void ScavTrap::beRepaired(unsigned int amount) {
// 	if (this->_energy == 0)
// 	{
// 		std::cout << this->_name << "has not enough energy to repaidred itself" << std::endl;
// 		return ;
// 	}
// 	this->_energy -= 1;
// 	this->_hp += amount;
// 	std::cout << std::endl << this->_name << " healed himself for " << amount << " hp(s)" << std::endl;
// 	std::cout << this->_name << " has " <<  this->_hp << " hp(s)" << std::endl;
// 	std::cout << this->_name << " has " << this->_energy << " energy left" << std::endl << std::endl;
// }