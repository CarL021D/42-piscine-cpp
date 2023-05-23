/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:49:43 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/22 20:20:44 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	
	ClapTrap player1 = ClapTrap("player1");
	ClapTrap player2 = ClapTrap("player2");
	
	player1.setDamage(1);
	player2.setDamage(100);

	for (uint8_t i = 0; i < 8; i++) {
		player1.attack("player2");
		player2.takeDamage(1);
	}
	player2.beRepaired(8);
	for (uint8_t i = 0; i < 2; i++) {
	
		player1.attack("player2");
		player2.takeDamage(1);
	}	
	player1.attack("player2");
	for (uint8_t i = 0; i < 2; i++) {
		player2.attack("player1");
		player1.takeDamage(100);
	}
}