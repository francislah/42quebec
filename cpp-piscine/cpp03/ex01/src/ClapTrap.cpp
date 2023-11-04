#include "ClapTrap.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), \
	_energyPoints(10), _attackDamage(0)
	{std::cout << "Default construction" << std::endl;}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), \
_energyPoints(10), _attackDamage(0){std::cout << "Construction" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name), \
	_hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), \
	_attackDamage(copy._attackDamage)
	{std::cout << "Copy construction" << std::endl;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

void	ClapTrap::attack(const std::string& target){
	if (this->_hitPoints == 0){std::cout << this->_name << " is dead..." << std::endl;}
	else if (this->_energyPoints > 0) {
		std::cout << this->_name << " attacks " << target << "!" << std::endl;
		std::cout << target << " loses " << this->_attackDamage << " hit points" << std::endl;
		this->_energyPoints -= 1;}
	else {std::cout << "Not enough energy..." << std::endl;}}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints == 0) {std::cout << this->_name << " is dead..." << std::endl;}
	else if (this->_energyPoints > 0 && this->_hitPoints > amount) {
		std::cout << this->_name << " takes " << amount << " of damage!" << std::endl;
		this->_hitPoints -= amount;
		std::cout << this->_name << " now has " << this->_hitPoints << " hit points";
		std::cout << std::endl;}
	else {std::cout << this->_name << " got killed!" << std::endl;this->_hitPoints = 0;}}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0){std::cout << this->_name << " is dead..." << std::endl;}
	else if (this->_energyPoints > 0) {
		std::cout << this->_name << " repairs himself by " << amount << " hit points!" << std::endl;
		this->_hitPoints += amount;
		std::cout << this->_name << " now has " << this->_hitPoints << " hit points" << std::endl;
		this->_energyPoints -= 1;}
	else {std::cout << "Not enough energy..." << std::endl;}}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy){
	if (this != &copy){
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;}
	std::cout << "Copy assignment constructor" << std::endl;
	return (*this);}

//************************************************** ************************//
//                               Destructors                                //
//**************************************************************************//

ClapTrap::~ClapTrap(void){std::cout << "Destruction" << std::endl;}