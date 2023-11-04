#include "ScavTrap.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

ScavTrap::ScavTrap(void): ClapTrap("Default Scav") {
	_name = "Default Scav";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Scav construction" << std::endl;}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Scav construction" << std::endl;}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	std::cout << "Scav copy construction" << std::endl;
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

void	ScavTrap::guardGate() {
	std::cout << this->_name << " is keeping the gate" << std::endl;}

void	ScavTrap::attack(const std::string& target){
	if (this->_hitPoints == 0){std::cout << this->_name << " is dead..." << std::endl;}
	else if (this->_energyPoints > 0) {
		std::cout << this->_name << " slowly attacks " << target << "!" << std::endl;
		std::cout << target << " loses " << this->_attackDamage << " hit points" << std::endl;
		this->_energyPoints -= 1;}
	else {std::cout << "Not enough energy..." << std::endl;}}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy){
	if (this != &copy){
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;}
	std::cout << "Scav copy assignement" << std::endl;
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

ScavTrap::~ScavTrap(void){std::cout << "Scav destruction" << std::endl;}