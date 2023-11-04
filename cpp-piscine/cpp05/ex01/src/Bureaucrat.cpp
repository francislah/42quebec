#include "Bureaucrat.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
	std::cout << "Bureaucrat default construction" << std::endl;}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat construction" << std::endl;}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : 
	_name(copy._name),
	_grade(copy._grade) {
	std::cout << "Bureaucrat copy construction" << std::endl;
	*this = copy;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

void	Bureaucrat::setGrade(int grade) {
	if (grade > 150) {throw GradeTooLowException(grade);}
	else if (grade < 1) {throw GradeTooHighException(grade);}
	else {this->_grade = grade;}}

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

const std::string	Bureaucrat::getName(void) const{return (this->_name);}
int	Bureaucrat::getGrade(void) {return (this->_grade);}

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

void	Bureaucrat::incrementGrade(void) {
	if (this->_grade == 1) {
		throw GradeTooHighException(this->_grade);}
	this->_grade--;}

void	Bureaucrat::decrementGrade(void) {
	if (this->_grade == 150){
		throw GradeTooLowException(this->_grade);}
	this->_grade++;}

void	Bureaucrat::signForm(Form& form) {
	try {form.beSigned(*this);}
	catch (Form::GradeTooLowException& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName();
		std::cout << " because " << e.what() << std::endl;
		return;}
	std::cout << this->getName() << " signed " << form.getName() << std::endl;}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy){
	if (this != &copy){
		this->_grade = copy._grade;}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

Bureaucrat::~Bureaucrat(void){std::cout << "Bureaucrat destruction" << std::endl;}

//**************************************************************************//
//                              Friend function                             //
//**************************************************************************//

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat._name << ", bureaucrat grade " << bureaucrat._grade;
	return (out);}
