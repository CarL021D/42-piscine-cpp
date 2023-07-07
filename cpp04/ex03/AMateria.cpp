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

#include "includes/includes.hpp"

AMateria::AMateria() {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& src) { *this = src; }

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria& AMateria::operator=(const AMateria& rhs) {
	this->_type = rhs.getType();
	return *this;
}

std::string const & AMateria::getType() const { return this->_type; }

void AMateria::setType(std::string type) { this->_type = type; }