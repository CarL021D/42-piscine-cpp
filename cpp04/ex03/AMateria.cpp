/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:27:50 by caboudar          #+#    #+#             */
/*   Updated: 2023/06/16 12:18:38 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/AMateria.hpp"

AMateria::AMateria() { std::cout << "Amateria constructor called" << std::endl; }

AMateria::~AMateria() { std::cout << "Amateria destructor called" << std::endl; }

AMateria::AMateria(AMateria& const cpy) { *this = cpy; }

AMateria& AMateria::operator=(AMateria& const rhs) { return *this; }