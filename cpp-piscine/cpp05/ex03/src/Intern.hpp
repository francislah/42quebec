#ifndef	INTERN_HPP
# define	INTERN_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Bureaucrat;
class Form;

class Intern{
public:
//Default constructor (Required)
	Intern(void);
//Copy constructor (Required)
	Intern (const Intern &copy );
//Constructors
//Default Destructor (Required)
	~Intern();
//Destructors
//Copy assignment operator (Required)
	Intern & operator = (const Intern &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	Form	*makeForm(std::string form_name, std::string target);

	class FormDoesntExist : public std::exception {
	public:
		FormDoesntExist(void) {};
		const char* what() const throw() {return ("Form doesn't exist!");};
	};

private:
protected:
};

#endif