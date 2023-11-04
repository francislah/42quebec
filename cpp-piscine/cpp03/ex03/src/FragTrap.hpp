#ifndef CPP03_EX03_FRAGTRAP_HPP
# define CPP03_EX03_FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
public:
//Default constructor (Required)
	FragTrap(void);
//Copy constructor (Required)
	FragTrap (const FragTrap &copy);
//Constructors
	FragTrap (std::string name);
//Default Destructor (Required)
	virtual ~FragTrap (void);
//Destructors
//Copy assignment operator (Required)
	FragTrap & operator = (const FragTrap &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	void	highFivesGuys(void);
	private:
};

#endif