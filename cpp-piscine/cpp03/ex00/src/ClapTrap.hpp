#ifndef	CPP_EX00_CLAPTRAP_HPP
# define	CPP_EX00_CLAPTRAP_HPP

# include <iostream>


#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

class ClapTrap{
public:
//Default constructor (Required)
	ClapTrap (void);
//Copy constructor (Required)
	ClapTrap (const ClapTrap &copy );
//Constructors
	ClapTrap (std::string name);
//Default Destructor (Required)
	~ClapTrap ( void );
//Destructors
//Copy assignment operator (Required)
	ClapTrap & operator = (const ClapTrap &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
void	attack(const std::string& target);
void	takeDamage(unsigned int amount);
void	beRepaired(unsigned int amount);

private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};
#endif // CLAPTRAP_HPP_


#endif