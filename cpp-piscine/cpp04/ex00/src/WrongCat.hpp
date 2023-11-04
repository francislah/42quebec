#ifndef	CPP04_EX00_WRONGCAT_HPP
# define	CPP04_EX00_WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal{
public:
//Default constructor (Required)
	WrongCat(void);
//Copy constructor (Required)
	WrongCat (const WrongCat &copy );
//Constructors
//Default Destructor (Required)
	~WrongCat(void);
//Destructors
//Copy assignment operator (Required)
	WrongCat & operator = (const WrongCat &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	void	makeSound(void);

protected:
};

#endif