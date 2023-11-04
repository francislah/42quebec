#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	FragTrap pizza;
	FragTrap a(pizza);
	FragTrap b;

	b = a;
	std::cout << std::endl;
	std::cout << "Name: " << pizza.getName() << std::endl;
	std::cout << "Hit points: " << pizza.getHitPoints() << std::endl;
	std::cout << "Energy points: " << pizza.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << pizza.getAttackDamage() << std::endl;
	pizza.attack("Burger");
	pizza.highFivesGuys();
	std::cout << std::endl;
	return (0);} 