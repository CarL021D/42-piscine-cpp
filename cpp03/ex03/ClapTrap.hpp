/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:49:39 by caboudar          #+#    #+#             */
/*   Updated: 2023/08/02 12:05:23 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdint.h>

class ClapTrap {

	public:
		ClapTrap();
		ClapTrap(std::string name);
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap& src);
		ClapTrap& operator=(const ClapTrap& rhs);

		virtual	void 	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			setDamage(unsigned int amount);
		unsigned int	getDamage();
	protected:
		std::string		_name;
		int				_hp;
		unsigned int	_energy;
		unsigned int	_attackDamage;	
};
