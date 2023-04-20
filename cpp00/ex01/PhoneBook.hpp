#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	
public:

	Contact		contact[8];

	PhoneBook();
	~PhoneBook();

	void			add_contact(Contact contact);
	void			look_for_contact_info();

private:

	short			space_count(std::string str);
	bool			contact_index_error(std::string index_str);
	std::string		truncate_str(std::string str);
	void			display_contacts_info();
	void			print_content(std::string input);
	void			single_contact_info_display(std::string input);
};

#endif
