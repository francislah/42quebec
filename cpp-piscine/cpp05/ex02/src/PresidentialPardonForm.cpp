#include "PresidentialPardonForm.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Default", 25, 5){
	std::cout << "PresidentialPardonForm default construction" << std::endl;}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	Form(target, 25, 5) {
	std::cout << "PresidentialPardonForm default construction" << std::endl;}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : 
	Form(copy) {
	std::cout << "PresidentialPardonForm copy construction" << std::endl;
	*this = copy;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

void	PresidentialPardonForm::formAction(void) const {
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblerox!" << std::endl;}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	if (this != &copy){
		Form::operator=(copy);}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

PresidentialPardonForm::~PresidentialPardonForm(void){std::cout << "PresidentialPardonForm destruction" << std::endl;}

//**************************************************************************//
//                              Friend function                             //
//**************************************************************************//

