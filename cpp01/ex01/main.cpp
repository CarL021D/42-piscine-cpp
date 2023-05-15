/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:28 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:43:29 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {

	Zombie* zombieArr = zombieHorde(4, "Bob");
	for (uint32_t i = 0; i < 4; i++)
		zombieArr[i].announce();
	delete [] zombieArr;
}