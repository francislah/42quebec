#include "Zombie.hpp"

int	main( void ) {
	Zombie	*zombie_horde;

	zombie_horde = zombieHorde(10, "Zombieee");
	delete [] zombie_horde;
	return 0;
}