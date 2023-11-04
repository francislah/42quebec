#ifndef CPP00_EX00_PHONEBOOK_H
#define CPP00_EX00_PHONEBOOK_H

#include <iomanip>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int		_n_contacts;
		Contact	_contact[8];
		
	public:

		void	new_contact( void );
		Contact	get_contact( int index );
		int		display_contacts(PhoneBook phonebook);
		int		get_index( void );
		void	add_index( void );

		PhoneBook();
		~PhoneBook();
};

#endif
