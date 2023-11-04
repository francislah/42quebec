#include "ClapTrap.hpp"

int	main(void){
	ClapTrap	a("Pizza");
	ClapTrap	b;
	ClapTrap	c;
	ClapTrap	d(b);

	c = b;
	b.takeDamage(1);
	c.takeDamage(1);
	d.takeDamage(1);
	a.beRepaired(1);
	a.attack("Burger");
	for (int i = 0; i < 12; i++){a.takeDamage(1);}
	for (int i = 0; i < 11; i++){b.attack("Burger");}
}
	//for (int i = 0; i < 11; i++){a.attack("Poutine");}
	//for (int i = 0; i < 11; i++){a.beRepaired(1);}