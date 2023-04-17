#include <iostream>
#include <cstdint>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) {
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

PhoneBook		PhoneBook::add_contact(PhoneBook phoneB, Contact contact)
{
	int8_t	i = 7;

	while (i >= 0)
	{
		phoneB.contact[i - 1] = phoneB.contact[i];
		i--;
	}
	phoneB.contact[0] = contact;
	return phoneB;
}
