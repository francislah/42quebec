
#include "Harl.hpp"

Harl::Harl( void ) {
	return;
}

void	Harl::debug( void ){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-\
ketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough \
bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	return ;
}

void	Harl::warning( void ){
	std::cout <<  "I think I deserve to have some extra bacon for free. I've been coming for \
years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain( std::string level ) {
	void	(Harl::*complaint[])( void ) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};
	std::string	c_level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; complaint[i]; i++) {
		void	(Harl::*select_complaint) ( void ) = complaint[i];
		if (level == c_level[i]) {
			(this->*select_complaint)();
		}
	}
	return ;
}

Harl::~Harl( void ) {
	return;
}
