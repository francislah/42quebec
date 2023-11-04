#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Intern a;

	std::cout << std::endl;
	try {a.makeForm("robotomy request", "bender");}
	catch(Intern::FormDoesntExist& e) {std::cout << e.what() << std::endl;}
	std::cout << std::endl;
	try {a.makeForm("lobotomy request", "bender");}
	catch(Intern::FormDoesntExist& e) {std::cout << e.what() << std::endl;}
	std::cout << std::endl;

	return (0);}