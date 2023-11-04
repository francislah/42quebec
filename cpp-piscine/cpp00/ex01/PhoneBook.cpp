#include "PhoneBook.hpp"

void	PhoneBook::add_index( void ) {
	this->_n_contacts++;
}

int	PhoneBook::get_index( void ) {
	return (this->_n_contacts);
}

Contact	 PhoneBook::get_contact( int index ) {
	return (this->_contact[index]);
}

int	print_contact_info(PhoneBook phonebook, std::string input) {
	Contact	contact;
	int	index = std::stoi(input);

	std::cout << input;
	if (index < 1 && index > phonebook.get_index())
		return (1);
	index -= 1;
	std::cout << "\n\e[1;32mContact #" << index + 1 << " :\e[0m\n";
	contact = phonebook.get_contact(phonebook.get_index());
	contact.displayContact();
	return (0);
}

void	PhoneBook::new_contact( void ) {
	static int	i = 0;
	static int	full = false;

	if (i == 8) {
		full = true;
		i = 0;
	}
	this->_contact[i].createContact(i, full);
	i++;
}

int	PhoneBook::display_contacts(PhoneBook phonebook) {
	Contact contact;
	std::cout << "\n\e[1;32m     Index|First Name| Last Name|  Nickname\e[0m\n";
	for (int index = 0; index < phonebook.get_index(); index++) {
		contact = phonebook.get_contact(index);
		contact.print_informations(std::to_string(index + 1));
		std::cout << "|";
		contact.displayContact();
	}
	if (phonebook.get_index() == 0) {
		std::cout << "\e[1;31mPhoneBook is empty... Go add contacts!\e[0m\n";
		return (1);
	}
	return (0);
}

PhoneBook::PhoneBook()
{
	this->_n_contacts = 0;
	return ;
}

PhoneBook::~PhoneBook()
{

}
