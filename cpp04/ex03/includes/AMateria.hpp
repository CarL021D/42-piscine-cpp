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
			virtual ~AMateria();
			AMateria(const AMateria& src);
			AMateria(const std::string& type);
			AMateria& operator=(const AMateria& rhs);

			virtual AMateria* 	clone() const = 0;
			virtual void		use(ICharacter& target) = 0;
			std::string const & getType() const;
			void				setType(std::string type);
	protected:
			std::string _type;
};