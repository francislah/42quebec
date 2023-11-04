#include "ShrubberyCreationForm.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Default", 145, 137){
	std::cout << "ShrubberyCreationForm default construction" << std::endl;}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	Form(target, 145, 137) {
	std::cout << "ShrubberyCreationForm default construction" << std::endl;}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : 
	Form(copy) {
	std::cout << "ShrubberyCreationForm copy construction" << std::endl;
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

void	ShrubberyCreationForm::formAction(void) const {
	std::ofstream outfile;

	outfile.open(this->getName() + "_shrubbery", std::ios::out);
	if (!outfile.good()) {
		std::cout << "Error: unable to open file" << std::endl;
		return;}
	outfile << "  *  " << std::endl;
	outfile << " *** " << std::endl;
	outfile << "*****" << std::endl;
	outfile.close();
}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
	if (this != &copy){
		Form::operator=(copy);}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

ShrubberyCreationForm::~ShrubberyCreationForm(void){std::cout << "ShrubberyCreationForm destruction" << std::endl;}

//**************************************************************************//
//                              Friend function                             //
//**************************************************************************//

