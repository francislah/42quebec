#ifndef CPP03_EX03_DIAMONDTRAP_HPP
# define CPP03_EX03_DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
public:
//Default constructor (Required)
	DiamondTrap(void);
//Copy constructor (Required)
	DiamondTrap (const DiamondTrap &copy);
//Constructors
	DiamondTrap (std::string name);
//Default Destructor (Required)
	virtual ~DiamondTrap (void);
//Destructors
//Copy assignment operator (Required)
	DiamondTrap & operator = (const DiamondTrap &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	void	whoAmI();
	using 	ScavTrap::attack;
private:
	std::string	_name;
};

#endif