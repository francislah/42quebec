#ifndef	CPP04_EX00_CAT_HPP
# define	CPP04_EX00_CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal{
public:
//Default constructor (Required)
	Cat(void);
//Copy constructor (Required)
	Cat (const Cat &copy );
//Constructors
//Default Destructor (Required)
	~Cat(void);
//Destructors
//Copy assignment operator (Required)
	Cat & operator = (const Cat &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	void	makeSound(void);

protected:
};

#endif