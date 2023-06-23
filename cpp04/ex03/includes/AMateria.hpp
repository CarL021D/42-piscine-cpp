/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:27:54 by caboudar          #+#    #+#             */
/*   Updated: 2023/06/16 12:25:17 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "includes.hpp"

class ICharacter;

class AMateria {
	public:
			AMateria();
			~AMateria();
			AMateria(const AMateria& cpy);
			AMateria(const std::string& type);
			AMateria& operator=(const AMateria& rhs);

			virtual AMateria* 	createMateria(std::string type) = 0;
			virtual AMateria* 	clone() const = 0;
			virtual void		use(ICharacter& target) = 0;
			std::string const & getType() const;
	protected:
			std::string _type;
};