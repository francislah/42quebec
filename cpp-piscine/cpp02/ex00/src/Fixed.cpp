#include "Fixed.hpp"


//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);}

Fixed::Fixed (const Fixed &fixed ) {
	*this = fixed;
	std::cout << "Copy constructor called" << std::endl;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

void	Fixed::setRawBits( int const raw ) {
	this->_fixed_point_number = raw;}

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

int	Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_number);}

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

Fixed &Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignement operator called" << std::endl;
	this->_fixed_point_number = fixed.getRawBits();
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;}
