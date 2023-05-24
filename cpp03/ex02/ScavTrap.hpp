/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:30:19 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/24 10:19:57 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

class ScavTrap : public ClapTrap {
	public:

		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();

		void	guardGate();
		void 	attack(const std::string& target);
	
	private:
};
