/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:49:43 by caboudar          #+#    #+#             */
/*   Updated: 2023/07/31 11:58:25 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	
	ClapTrap player1 = ClapTrap("player1");
	ScavTrap player2 = ScavTrap("player2");
	
	std::cout << std::endl;
	player2.guardGate();
	std::cout << std::endl;
	for (uint8_t i = 0; i < 2; i++) {
		player1.attack("player2");
		player2.takeDamage(player1.getAttackDamage());
	}
	player2.beRepaired(8);
	for (uint8_t i = 0; i < 2; i++) {
		player2.attack("player1");
		player1.takeDamage(player2.getAttackDamage());
	}
}