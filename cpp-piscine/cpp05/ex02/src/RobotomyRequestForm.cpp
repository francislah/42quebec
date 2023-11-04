#include "RobotomyRequestForm.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Default", 72, 45){
	std::cout << "RobotomyRequestForm default construction" << std::endl;}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	Form(target, 72, 45) {
	std::cout << "RobotomyRequestForm default construction" << std::endl;}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : 
	Form(copy) {
	std::cout << "RobotomyRequestForm copy construction" << std::endl;
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

void	RobotomyRequestForm::formAction(void) const {
	std::srand(time(NULL));
	std::cout << "\"BzZZzzzBBzzzzbBzzzzbZBzzz\"" << std::endl;
	int x = std::rand();
	if (x % 2 == 0) {
		std::cout << this->getName() << " robotomised successfully!" << std::endl;}
	else {
		std::cout << this->getName() << " robotomisation failure..." << std::endl;}}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
	if (this != &copy){
		Form::operator=(copy);}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

RobotomyRequestForm::~RobotomyRequestForm(void){std::cout << "RobotomyRequestForm destruction" << std::endl;}

//**************************************************************************//
//                              Friend function                             //
//**************************************************************************//

