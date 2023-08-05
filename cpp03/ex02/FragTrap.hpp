/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:53:03 by caboudar          #+#    #+#             */
/*   Updated: 2023/08/05 02:08:24 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
			FragTrap();
			FragTrap(std::string name);
			~FragTrap();
			FragTrap(const FragTrap& src);
			FragTrap& operator=(const FragTrap& rhs);

			void highFiveGuys();
};
