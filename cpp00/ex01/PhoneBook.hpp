#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	
public:
	Contact		contact[8];

	PhoneBook();
	~PhoneBook();

	PhoneBook	add_contact(PhoneBook phoneB, Contact contact);
	short		space_count(std::string str);
	std::string	truncate_str(std::string str);
	bool		contact_index_error(PhoneBook phoneB, std::string index_str);
	void		print_content(std::string input);
	void		display_contact_info(PhoneBook phoneB);


private:
};

#endif
