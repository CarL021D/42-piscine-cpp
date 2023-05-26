/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:03:06 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/24 17:40:11 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: virtual public FragTrap, virtual public ScavTrap {

	public:
	
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();

		void whoAmI();
		using ScavTrap::attack;

	private:
		std::string name;
};
