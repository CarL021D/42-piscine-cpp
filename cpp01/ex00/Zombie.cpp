/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:20 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:43:21 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() { std::cout << _name << " destructor called" << std::endl; }

void Zombie::setName(std::string name) { _name = name; }

void Zombie::announce() { std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
