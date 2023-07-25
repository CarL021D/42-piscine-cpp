/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:05 by caboudar          #+#    #+#             */
/*   Updated: 2023/07/25 16:19:23 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <stdint.h>

class Contact {
	public:
		Contact();
		~Contact();

	void			create_contact();
	std::string		getFirstName() const;
	std::string		getLastName() const;
	std::string		getNickName() const;
	std::string		getPhoneNumber() const;
	std::string		getDarketSecret() const;

	private:
			std::string		_firstName;
			std::string		_lastName;
			std::string		_nickName;
			std::string		_phoneNumber;
			std::string		_darkestSecret;
};

#endif