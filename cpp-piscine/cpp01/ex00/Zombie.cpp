#include "Zombie.hpp"

void	Zombie::announce( void ) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string name ) : _name(name) {
	announce();
}

Zombie::Zombie( void ) {

}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " destroyed!" << std::endl;
}
