#include "Weapon.hpp"

Weapon::Weapon( std::string newType ) {
	_type = newType;
}

Weapon::~Weapon( void ) {
	return ;
}

std::string const &Weapon::getType( void ) const{
	return (this->_type);
}

void	Weapon::setType( std::string newType ) {
	this->_type = newType;
	return ;
}