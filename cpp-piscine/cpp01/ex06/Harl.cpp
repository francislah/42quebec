
#include "Harl.hpp"

Harl::Harl( void ) {
	return;
}

void	Harl::insignificant( void ) {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-\
ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
	return ;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough \
bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
	return ;
}

void	Harl::warning( void ){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout <<  "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
	return ;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
	return ;
}

void	Harl::complain( std::string level ) {
	void	(Harl::*complaint[])( void ) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};
	std::string	c_level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	index = -1;
	for (int i = 0; complaint[i]; i++) {
		if (level == c_level[i]) {index = i; break;}
	}
	switch (index) {
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break ;
		case -1:
			insignificant();
		default:
			break ;
	}
	return ;
}

Harl::~Harl( void ) {
	return;
}
