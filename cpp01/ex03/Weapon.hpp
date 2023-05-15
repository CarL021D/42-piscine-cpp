/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:45:17 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:45:18 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once
#include <iostream>

class Weapon {

    public:

		Weapon();
        Weapon(std::string type);
		~Weapon();

		const std::string	&getType();
		void				setType(std::string type);

	private:
		std::string		_type;

};
