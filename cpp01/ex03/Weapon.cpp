/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:45:13 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:45:14 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

const std::string   &Weapon::getType() { return _type; }

void				Weapon::setType(std::string type) { _type = type; }
