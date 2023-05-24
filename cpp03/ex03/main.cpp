/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:49:43 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/24 17:17:44 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	
	ScavTrap 	player1 = ScavTrap("player1");
	FragTrap	player2 = FragTrap("player2");
	DiamondTrap	player3 = DiamondTrap("player3");
	
	player2.highFiveGuys();
	for (uint8_t i = 0; i < 2; i++) {
		player1.attack("player2");
		player2.takeDamage(1);
	}
	player2.beRepaired(8);
	for (uint8_t i = 0; i < 2; i++) {
		player2.attack("player1");
		player1.takeDamage(20);
	}
}