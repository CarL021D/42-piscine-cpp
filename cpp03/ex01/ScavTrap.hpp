/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:30:19 by caboudar          #+#    #+#             */
/*   Updated: 2023/07/31 11:52:21 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class ScavTrap : public ClapTrap {
	public:

		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();

		void	guardGate();
		void 	attack(const std::string& target);
};
