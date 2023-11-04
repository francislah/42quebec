#include "Form.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

Form::Form(void) :
	_name(""),
	_signature(false),
	_grade_sign(150),
	_grade_exec(150) {
	std::cout << "Form default construction" << std::endl;}

Form::Form(const std::string& name, int grade_sign, int grade_exec) :
	_name(name),
	_signature(false),
	_grade_sign(setGrade(grade_sign)),
	_grade_exec(setGrade(grade_exec)) {
	std::cout << "Form construction" << std::endl;}

Form::Form(const Form &copy) : 
	_name(copy._name),
	_signature(copy._signature),
	_grade_sign(copy._grade_sign),
	_grade_exec(copy._grade_exec) {
	std::cout << "Form copy construction" << std::endl;
	*this = copy;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

int	Form::setGrade(int grade) {
	if (grade > 150) {throw GradeTooLowException(grade);}
	else if (grade < 1) {throw GradeTooHighException(grade);}
	return grade;}

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

const std::string	Form::getName(void) const {return (this->_name);}
int	Form::getGradeSign(void) const {return (this->_grade_sign);}		
int	Form::getGradeExec(void) const {return (this->_grade_exec);}
bool	Form::getSigned(void) const {return (this->_signature);}

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeSign()) {
		throw GradeTooLowException(bureaucrat.getGrade());}
	this->_signature = true;}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

Form	&Form::operator=(const Form &copy){
	if (this != &copy){
		this->_signature = copy._signature;}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

Form::~Form(void){std::cout << "Form destruction" << std::endl;}

//**************************************************************************//
//                              Friend function                             //
//**************************************************************************//

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "Form: " << form.getName() << " | Signed: ";
	if (form.getSigned() == 1) {std::cout << "yes";}
	else {std::cout << "no";}
	out << " | Execute grade: " << form.getGradeExec();
	out << " | Sign grade: " << form.getGradeSign() << std::endl;
	return (out);}
