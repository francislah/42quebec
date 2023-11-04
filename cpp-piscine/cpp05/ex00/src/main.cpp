#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat	a;
	Bureaucrat	b("John", 1);
	
	std::cout << a << std::endl;
	try {a.decrementGrade();}
	catch (Bureaucrat::GradeTooHighException& e) {std::cout << e.what() << std::endl;}
	catch (Bureaucrat::GradeTooLowException& e) {std::cout << e.what() << std::endl;}
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	try {b.incrementGrade();}
	catch (Bureaucrat::GradeTooHighException& e) {std::cout << e.what() << std::endl;}
	catch (Bureaucrat::GradeTooLowException& e) {std::cout << e.what() << std::endl;}
	std::cout << b << std::endl;
	return (0);}