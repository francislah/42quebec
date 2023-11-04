#include "DiamondTrap.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

//ScavTrap defaults values gets overwritten on FragTrap creation
DiamondTrap::DiamondTrap(void): ScavTrap(), FragTrap() {
	_name = "Default Diamond";
	ClapTrap::_name = _name + "_clap_name";
	_energyPoints = 50;
	std::cout << "Diamond construction" << std::endl;}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name), FragTrap(name) {
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_energyPoints = 50;
	std::cout << "Diamond construction" << std::endl;}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ScavTrap(copy), FragTrap(copy) {
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	std::cout << "Diamond copy construction" << std::endl;
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

void	DiamondTrap::whoAmI() {
	 std::cout << this->_name << " or " << ClapTrap::getName() << "?" << std::endl;}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy){
	if (this != &copy){
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;}
	std::cout << "Diamond copy assignement" << std::endl;
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

DiamondTrap::~DiamondTrap(void){std::cout << "Diamond destruction" << std::endl;}