/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:30:19 by caboudar          #+#    #+#             */
/*   Updated: 2023/08/05 02:08:37 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ClapTrap.hpp>

class ScavTrap : public ClapTrap {
	public:
			ScavTrap();
			ScavTrap(std::string name);
			~ScavTrap();
			ScavTrap(const ScavTrap& src);
			ScavTrap& operator=(const ScavTrap& rhs);

			void	guardGate();
			void 	attack(const std::string& target);
};
