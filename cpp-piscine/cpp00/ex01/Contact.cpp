#include "Contact.hpp"

void	Contact::print_informations(std::string str) {
	int	len;
	
	len = str.length();
	for (int i = 0; i < 10 - len; i++) {
		std::cout << " ";
	}
	for(int j = 0; j < len; j++) {
		if (len > 10 && j == 9) {
			std::cout << ".";	
			break ;	
		}
		std::cout << str[j];
	}
}

void	Contact::displayContact( void ) {
	print_informations(_firstName);
	std::cout << "|";
	print_informations(_lastName);
	std::cout << "|";
	print_informations(_nickname);
	std::cout << "\n";
	return ;
}

void	Contact::displayContactInfo( void ) {
	std::cout << "\e[1;34mFirst Name:\e[0m " << _firstName << "\n";
	std::cout << "\e[1;34mLast Name: \e[0m" << _lastName << "\n";
	std::cout << "\e[1;34mNickname: \e[0m" << _nickname << "\n";
	std::cout << "\e[1;34mPhone Number: \e[0m" << _phoneNumber << "\n";
	std::cout << "\e[1;34mDarkest Secret: \e[0m" << _darkestSecret << "\n\n";
	return ;
}

void	Contact::createContact( int index, bool full ) {
	std::cout << "\n\e[1;32mCreating a new contact for the PhoneBook!\e[0m\n\n";
	if (full)
		std::cout << "\e[1;31mPhoneBook full! New contact will erase contact #" << index + 1 << "\e[0m\n\n";
	setFirstName();
	setLastName();
	setNickname();
	setPhoneNumber();
	setDarkestSecret();
	std::cout << "\n\e[1;32mNew contact #" << index +1 << " successfully added!\e[0m\n\n";
	return ;
}

void	Contact::setFirstName( void ) {
	std::string	input;

	std::cout << "Enter First Name: " << std::endl;
	std::getline(std::cin, input);
	while (input.empty() && !std::cin.eof()) {
		std::cout << "\e[1;31mEnter First Name (Cannot be empty!): \e[0m" << std::endl;
		std::getline(std::cin, input);
	}
	if (std::cin.eof())
			exit(0);
	_firstName = input;
	return ;
}


void	Contact::setLastName( void ) {
	std::string	input;

	std::cout << "Enter Last Name: " << std::endl;
	std::getline(std::cin, input);
	while (input.empty() && !std::cin.eof()) {
		std::cout << "\e[1;31mEnter Last Name (Cannot be empty!): \e[0m" << std::endl;
		std::getline(std::cin, input);
	}
	if (std::cin.eof())
		exit(0);
	_lastName = input;
	return ;
}

void	Contact::setNickname( void ) {
	std::string	input;

	std::cout << "Enter Nickname: " << std::endl;
	std::getline(std::cin, input);
	while (input.empty() && !std::cin.eof()) {
		std::cout << "\e[1;31mEnter Nickname (Cannot be empty!): \e[0m" << std::endl;
		std::getline(std::cin, input);
	}
	if (std::cin.eof())
		exit(0);
	_nickname = input;
	return ;
}

void	Contact::setPhoneNumber( void ) {
	std::string	input;

	std::cout << "Enter Phone Number: " << std::endl;
	std::getline(std::cin, input);
	while (input.empty() && !std::cin.eof()) {
		std::cout << "\e[1;31mEnter Phone Number (Cannot be empty!): \e[0m" << std::endl;
		std::getline(std::cin, input);
	}
	if (std::cin.eof())
		exit(0);
	_phoneNumber = input;
	return ;
}

void	Contact::setDarkestSecret(void) {
	std::string	input;

	std::cout << "Enter Darkest Secret: " << std::endl;
	std::getline(std::cin, input);
	while (input.empty() && !std::cin.eof()) {
		std::cout << "\e[1;31mEnter Darkest Secret (Cannot be empty!): \e[0m" << std::endl;
		std::getline(std::cin, input);
	}
	if (std::cin.eof())
		exit(0);
	_darkestSecret = input;
}

Contact::Contact(void)
{

}

Contact::~Contact()
{

}
