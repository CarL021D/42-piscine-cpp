/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:30:19 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/22 21:35:54 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ClapTrap.hpp>

class ScavTrap : public ClapTrap {
	public:

		ScavTrap() : ScapTrap()
		ScavTrap(std::string name);
		~ScavTrap();
		// void attack(const std::string& target);
		// void takeDamage(unsigned int amount);
		// void beRepaired(unsigned int amount);
		// void setDamage(unsigned int amount);

	private:
		std::string		_name;
		int				_hp;
		unsigned int	_energy;
		unsigned int	_attackDamage;
};
