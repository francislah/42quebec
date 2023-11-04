#include "Zombie.hpp"

void	am_i_dead_dead(Zombie zombie_stack, Zombie *zombie_heap) {
	std::cout << "\nzombie_stack announce: ";
	zombie_stack.announce();
	std::cout << "zombie_heap announce: ";
	zombie_heap->announce();
}

int	main( void ) {
	Zombie	zombie_stack("Frankenstein_stack");
	Zombie	*zombie_heap = newZombie("Zombie_heap");

	am_i_dead_dead(zombie_stack, zombie_heap);
	std::cout << "and this is why heap objects are useful...\n" << std::endl;
	randomChump("elvis");
	delete zombie_heap;
	return (0);
}