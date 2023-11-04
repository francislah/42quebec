#ifndef	CPP04_EX01_BRAIN_HPP
# define	CPP04_EX01_BRAIN_HPP

# include <iostream>

class Brain{
public:
//Default constructor (Required)
	Brain(void);
//Copy constructor (Required)
	Brain (const Brain &copy );
//Constructors
//Default Destructor (Required)
	virtual ~Brain(void);
//Destructors
//Copy assignment operator (Required)
	Brain & operator = (const Brain &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions

protected:

private:
	std::string	_ideas[100];
};

#endif