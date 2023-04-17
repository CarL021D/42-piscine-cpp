#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	
public:
	Contact		contact[8];

	PhoneBook();
	~PhoneBook();

	PhoneBook add_contact(PhoneBook phoneB, Contact contact);
private:
};

#endif
