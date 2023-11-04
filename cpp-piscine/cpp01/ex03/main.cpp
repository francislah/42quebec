# include "HumanA.hpp"
# include "HumanB.hpp"
# include "Weapon.hpp"

int	main( void ) {
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("bob", club);
		bob.attack();
		club.setType("Metal hammer");
		bob.attack();
	}
		std::cout << std::endl;
	{
		Weapon club2 = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club2);
		jim.attack();
		club2.setType("sword");
		jim.attack();
	}
	return (0);
}
