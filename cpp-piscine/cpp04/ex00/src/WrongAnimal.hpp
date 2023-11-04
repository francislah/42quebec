#ifndef	CPP04_EX00_WRONGANIMAL_HPP
# define	CPP04_EX00_WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal{
public:
//Default constructor (Required)
	WrongAnimal(void);
//Copy constructor (Required)
	WrongAnimal (const WrongAnimal &copy );
//Constructors
	WrongAnimal (std::string type);
//Default Destructor (Required)
	virtual ~WrongAnimal(void);
//Destructors
//Copy assignment operator (Required)
	WrongAnimal & operator = (const WrongAnimal &copy);
//Operators
//Swap function
//Setters & Getters
	std::string	getType(void);
//Other functions
	void	makeSound(void);

protected:
	std::string		_type;
};

#endif