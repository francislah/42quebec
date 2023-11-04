#ifndef	CPP05_EX02_PRESIDENTIAL_PARDON_FORM_HPP
# define	CPP05_EX02_PRESIDENTIAL_PARDON_FORM_HPP

# include "Form.hpp"

class Bureaucrat;
class Form;

class PresidentialPardonForm : public Form {
public:
//Default constructor (Required)
	PresidentialPardonForm(void);
//Copy constructor (Required)
	PresidentialPardonForm (const PresidentialPardonForm &copy );
//Constructors
	PresidentialPardonForm(std::string target);
//Default Destructor (Required)
	~PresidentialPardonForm();
//Destructors
//Copy assignment operator (Required)
	PresidentialPardonForm & operator = (const PresidentialPardonForm &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	void	formAction(void) const;

protected:
private:
};

#endif