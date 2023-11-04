#ifndef	CPP04_EX01_CAT_HPP
# define CPP04_EX01_CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

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

private:
	Brain	*_brain;
};

#endif