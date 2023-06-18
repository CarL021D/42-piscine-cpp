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
#include "includes/ICharacter.hpp"

AMateria::AMateria() { std::cout << "AMateria constructor called" << std::endl; }

AMateria::~AMateria() { std::cout << "AMateria destructor called" << std::endl; }

AMateria::AMateria(AMateria& const cpy) { *this = cpy; }

AMateria& AMateria::operator=(AMateria& const rhs) { return *this; }

const std::string AMateria::getType() { return this->type; }

AMateria* AMateria::clone() const {}

AMateria& AMateria::createMateria(std::string type) { /* set Amateria into an arr[3] of Amateria*/ }

void AMateria::use(ICharacter& target) { std::cout << ICharacter->name << ""}