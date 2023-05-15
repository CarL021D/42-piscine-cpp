/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:40 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:43:45 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdint.h>

class Zombie {

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void    setName(std::string name);
		void	announce();

	private:
		std::string     _name;
};

Zombie*	zombieHorde(int n, std::string name);
