#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name) {
	this->_weapon = NULL;
}

void	HumanB::setWeapon( Weapon &weaponType ) {
	this->_weapon = &weaponType;
	return ;
}

void	HumanB::attack( void ) const {
	if (this->_weapon) {
		std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
	}
	else {
		std::cout << this->_name << " attacks with their bare hands" << std::endl;
	}
}

HumanB::~HumanB( void ) {

}
