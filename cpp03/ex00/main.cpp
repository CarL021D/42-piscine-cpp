/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:49:43 by caboudar          #+#    #+#             */
/*   Updated: 2023/08/02 11:58:06 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	
	ClapTrap player1 = ClapTrap("player1");
	ClapTrap player2 = ClapTrap("player2");
	
	player1.setDamage(1);
	player2.setDamage(100);

	std::cout << std::endl;
	for (uint8_t i = 0; i < 8; i++) {
		player1.attack("player2");
		player2.takeDamage(player1.getDamage());
	}
	std::cout << std::endl;
	player2.beRepaired(8);
	std::cout << std::endl;
	for (uint8_t i = 0; i < 2; i++) {
	
		player1.attack("player2");
		player2.takeDamage(player1.getDamage());
	}
	std::cout << std::endl;
	player1.attack("player2");
	for (uint8_t i = 0; i < 2; i++) {
		player2.attack("player1");
		player1.takeDamage(player1.getDamage());
	}
}