#ifndef	CPP04_EX00_DOG_HPP
# define	CPP04_EX00_DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal{
public:
//Default constructor (Required)
	Dog(void);
//Copy constructor (Required)
	Dog (const Dog &copy );
//Constructors
//Default Destructor (Required)
	~Dog(void);
//Destructors
//Copy assignment operator (Required)
	Dog & operator = (const Dog &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	void	makeSound(void);

protected:
};

#endif