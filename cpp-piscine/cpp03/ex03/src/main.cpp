#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	DiamondTrap poutine;
	ScavTrap	a;
	FragTrap	b;
	std::cout << std::endl;

	std::cout << poutine.getAttackDamage() << " vs " << b.getAttackDamage() << std::endl;
	std::cout << poutine.getHitPoints() << " vs " << b.getHitPoints() << std::endl;
	std::cout << poutine.getEnergyPoints() << " vs " << a.getEnergyPoints() << std::endl;
	poutine.attack("Burger");
	poutine.whoAmI();
	poutine.guardGate();
	poutine.highFivesGuys();
	poutine.beRepaired(10);
	poutine.attack("Nobody");
	std::cout << std::endl << std::endl;
	DiamondTrap poutine2("Jon");

	std::cout << poutine2.getAttackDamage() << " diamond vs Frag " << b.getAttackDamage() << std::endl;
	std::cout << poutine2.getHitPoints() << " diamond vs Frag " << b.getHitPoints() << std::endl;
	std::cout << poutine2.getEnergyPoints() << " diamond vs Scav " << a.getEnergyPoints() << std::endl;
	std::cout << "Diamond attack: ";
	poutine2.attack("Burger");
	std::cout << "Scav attack: ";
	a.attack("Burger");
	poutine2.whoAmI();
	poutine2.guardGate();
	poutine2.highFivesGuys();
	poutine2.beRepaired(10);
	poutine2.attack("Nobody");
	std::cout << std::endl;

	return (0);} 