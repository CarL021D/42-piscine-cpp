/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:03:06 by caboudar          #+#    #+#             */
/*   Updated: 2023/08/03 14:14:30 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: virtual public ScavTrap, virtual public FragTrap {

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap& src);
		DiamondTrap& operator=(const DiamondTrap& rhs);

		void displayAttribut();
		void whoAmI();
		using ScavTrap::attack;

	private:
		std::string _name;
};
