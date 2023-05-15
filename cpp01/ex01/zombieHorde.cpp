/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:51 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:43:52 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name) {

	Zombie* zombieArr = new Zombie[n];
	for (int32_t i = 0; i < n; i++)
		zombieArr[i].setName(name);
	return zombieArr;
}