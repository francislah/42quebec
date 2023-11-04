#ifndef CPP03_EX03_SCAVTRAP_HPP
# define CPP03_EX03_SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
public:
//Default constructor (Required)
	ScavTrap(void);
//Copy constructor (Required)
	ScavTrap (const ScavTrap &copy);
//Constructors
	ScavTrap (std::string name);
//Default Destructor (Required)
	virtual ~ScavTrap (void);
//Destructors
//Copy assignment operator (Required)
	ScavTrap & operator = (const ScavTrap &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	void	guardGate();
	void	attack(const std::string& target);
	private:
};

#endif