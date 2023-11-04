#ifndef CPP00_EX00_CONTACT_H
#define CPP00_EX00_CONTACT_H

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		void	setFirstName( void );
		void	setLastName( void );
		void	setNickname( void );
		void	setPhoneNumber( void );
		void	setDarkestSecret( void );
		void	print_informations(std::string str);

		void	createContact( int index, bool full );
		void	displayContact( void );
		void	displayContactInfo( void );
		Contact();
		~Contact();
};

#endif
