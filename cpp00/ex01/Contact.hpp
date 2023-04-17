#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {

public:
	std::string		name;
	std::string		last_name;
	std::string		nickname;
	std::string		phone_number;
	std::string		darkest_secret;

	Contact();
	~Contact();

	Contact create_contact(void);

private:

};

#endif