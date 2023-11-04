#ifndef	CPP05_EX02_ROBOTOMY_REQUEST_FORM_HPP
# define	CPP05_EX02_ROBOTOMY_REQUEST_FORM_HPP

# include "Form.hpp"
# include <ctime>

class Bureaucrat;
class Form;

class RobotomyRequestForm : public Form {
public:
//Default constructor (Required)
	RobotomyRequestForm(void);
//Copy constructor (Required)
	RobotomyRequestForm (const RobotomyRequestForm &copy );
//Constructors
	RobotomyRequestForm(std::string target);
//Default Destructor (Required)
	~RobotomyRequestForm();
//Destructors
//Copy assignment operator (Required)
	RobotomyRequestForm & operator = (const RobotomyRequestForm &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	void	formAction(void) const;

protected:
private:
};

#endif