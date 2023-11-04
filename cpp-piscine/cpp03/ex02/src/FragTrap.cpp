#include "FragTrap.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

FragTrap::FragTrap(void): ClapTrap("Default Frag") {
	_name = "Default Frag";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Frag construction" << std::endl;}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Frag construction" << std::endl;}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	std::cout << "Frag copy construction" << std::endl;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

void	FragTrap::highFivesGuys(void) {
	std::cout << getName() << " request a high fives!" << std::endl;}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

FragTrap	&FragTrap::operator=(const FragTrap &copy){
	if (this != &copy){
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;}
	std::cout << "Frag copy assignement" << std::endl;
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

FragTrap::~FragTrap(void){std::cout << "Frag destruction" << std::endl;}