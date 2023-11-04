#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat	a("John", 50);
	Form		b("Application 1", 50, 49);
	Form		c("Application 2", 49, 49);

	std::cout << std::endl;
	a.signForm(b);
	a.signForm(c);
	std::cout << std::endl;

	return (0);}