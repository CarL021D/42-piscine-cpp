#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact {

public:
	char	*name;
	char	*last_name;
	char	*nickname;
	short	phone_number;

	Contact();
	~Contact();

	// void	get_contact(*Contact);
private:
};

#endif