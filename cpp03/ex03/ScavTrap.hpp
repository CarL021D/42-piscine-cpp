/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:30:19 by caboudar          #+#    #+#             */
/*   Updated: 2023/08/03 14:10:44 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
	public:
			ScavTrap();
			ScavTrap(std::string name);
			~ScavTrap();
			ScavTrap(const ScavTrap& src);
			ScavTrap& operator=(const ScavTrap& rhs);

			void	guardGate();
			void 	attack(const std::string& target);
	protected:
			int		_energy;
};
