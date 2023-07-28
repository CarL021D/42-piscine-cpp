/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:44:40 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:44:41 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name) {};

HumanB::~HumanB() {};

void    HumanB::setWeapon(Weapon& weapon) { _weapon = &weapon; }

void	HumanB::attack() {
	std::cout 	<< _name << " attacks with their "
				<< _weapon->getType() << std::endl;
}