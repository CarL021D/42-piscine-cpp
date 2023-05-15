/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:44:34 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:44:35 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon), _name(name) {};

HumanA::~HumanA() {};

void	HumanA::attack() {

	std::cout 	<< _name
				<< " attacks with their "
				<< _weapon.getType()
				<< std::endl;
}