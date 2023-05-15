/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:23 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:43:24 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie {

	public:
		Zombie();
		~Zombie();

		void	announce();
		void    setName(std::string name);

	private:
		std::string     _name;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);
