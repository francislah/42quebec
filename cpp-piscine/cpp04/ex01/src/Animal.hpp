#ifndef	CPP04_EX01_ANIMAL_HPP
# define	CPP04_EX01_ANIMAL_HPP

# include <iostream>

class Animal{
public:
//Default constructor (Required)
	Animal(void);
//Copy constructor (Required)
	Animal (const Animal &copy );
//Constructors
	Animal (std::string type);
//Default Destructor (Required)
	virtual ~Animal(void);
//Destructors
//Copy assignment operator (Required)
	Animal & operator = (const Animal &copy);
//Operators
//Swap function
//Setters & Getters
	std::string	getType(void);
//Other functions
	virtual void	makeSound(void);

protected:
	std::string		_type;
};

#endif