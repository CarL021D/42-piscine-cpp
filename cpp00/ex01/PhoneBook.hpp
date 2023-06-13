/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:20 by caboudar          #+#    #+#             */
/*   Updated: 2023/06/13 16:08:54 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <cctype>
#include <stdint.h>
#include "Contact.hpp"

class PhoneBook {
	
public:
	PhoneBook();
	~PhoneBook();
	void			add_contact(Contact contact);
	void			look_for_contact_info();

private:

	Contact			_contact[8];

	short			space_count(std::string str) const;
	bool			contact_index_error(std::string index_str) const;
	std::string		truncate_str(std::string str) const;
	void			display_contacts_info() const;
	void			print_content(std::string input) const;
	void			single_contact_info_display(std::string input) const;
};

#endif
