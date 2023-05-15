/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:44:37 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:44:38 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA {

	public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();

		void	attack();

	private:
		Weapon&			_weapon;
		std::string		_name;
};