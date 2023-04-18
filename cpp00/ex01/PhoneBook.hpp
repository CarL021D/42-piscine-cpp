#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	
public:
	Contact		contact[8];

	PhoneBook();
	~PhoneBook();

	void		add_contact(Contact contact);
	short		space_count(std::string str);
	std::string	truncate_str(std::string str);
	bool		contact_index_error(std::string index_str);
	void		print_content(std::string input);
	void		look_for_contact_info();


private:
};

#endif
