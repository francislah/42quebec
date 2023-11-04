#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Bureaucrat	a("John", 62);
	ShrubberyCreationForm	b;
	RobotomyRequestForm		c;
	PresidentialPardonForm	d;
	
	std::cout << std::endl;
	std::cout << "John execute form b: ";
	try {a.executeForm(b);}
	catch (Form::GradeTooLowException& e) {std::cout << e.what() << std::endl;}
	catch (Form::NoSignatureException& e) {std::cout << e.what() << std::endl;}
	std::cout << "John execute form c: ";
	try {a.executeForm(c);}
	catch (Form::GradeTooLowException& e) {std::cout << e.what() << std::endl;}
	catch (Form::NoSignatureException& e) {std::cout << e.what() << std::endl;}
	std::cout << "John execute form d: ";
	try {a.executeForm(d);}
	catch (Form::GradeTooLowException& e) {std::cout << e.what() << std::endl;}
	catch (Form::NoSignatureException& e) {std::cout << e.what() << std::endl;}
	std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << b;
	try {b.beSigned(a);}
	catch (Form::GradeTooLowException& e) {std::cout << e.what() << std::endl;}
	std::cout << c;
	try {c.beSigned(a);}
	catch (Form::GradeTooLowException& e) {std::cout << e.what() << std::endl;}
	std::cout << d;
	try {d.beSigned(a);}
	catch (Form::GradeTooLowException& e) {std::cout << e.what() << std::endl;}
	std::cout << std::endl;
	
	std::cout << "John execute form b: ";
	try {a.executeForm(b);}
	catch (Form::GradeTooLowException& e) {std::cout << e.what() << std::endl;}
	catch (Form::NoSignatureException& e) {std::cout << e.what() << std::endl;}
	std::cout << "John execute form c: ";
	try {a.executeForm(c);}
	catch (Form::GradeTooLowException& e) {std::cout << e.what() << std::endl;}
	catch (Form::NoSignatureException& e) {std::cout << e.what() << std::endl;}
	std::cout << "John execute form d: ";
	try {a.executeForm(d);}
	catch (Form::GradeTooLowException& e) {std::cout << e.what() << std::endl;}
	catch (Form::NoSignatureException& e) {std::cout << e.what() << std::endl;}
	std::cout << std::endl;

	return (0);}