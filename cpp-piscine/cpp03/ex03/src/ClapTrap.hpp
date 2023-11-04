#ifndef	CPP_EX03_CLAPTRAP_HPP
# define	CPP_EX03_CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
public:
//Default constructor (Required)
	ClapTrap(void);
//Copy constructor (Required)
	ClapTrap (const ClapTrap &copy );
//Constructors
	ClapTrap (std::string name);
//Default Destructor (Required)
	~ClapTrap(void);
//Destructors
//Copy assignment operator (Required)
	ClapTrap & operator = (const ClapTrap &copy);
//Operators
//Swap function
//Setters & Getters
	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackDamage() const;
//Other functions
void	attack(const std::string& target);
void	takeDamage(unsigned int amount);
void	beRepaired(unsigned int amount);

protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
};

#endif