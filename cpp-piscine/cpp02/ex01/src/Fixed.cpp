#include "Fixed.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

Fixed::Fixed( void ): _fixed_point_number(0) {
	std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed( const int num ) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_number = num << this->_n_fractional_bits;}

Fixed::Fixed( const float num ) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_number = roundf(num * 256);}

Fixed::Fixed (const Fixed &fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;}
//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

void	Fixed::setRawBits( int const raw ) {this->_fixed_point_number = raw;}

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

int	Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_number);}

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

int		Fixed::toInt( void ) const {
	return (this->_fixed_point_number >> this->_n_fractional_bits);}

float	Fixed::toFloat( void ) const {
	return ((float) this->_fixed_point_number / 256);}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

Fixed &Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixed)
		this->_fixed_point_number = fixed._fixed_point_number;
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

Fixed::~Fixed( void ) {std::cout << "Destructor called" << std::endl;}

//**************************************************************************//
//                             Outside functions                            //
//**************************************************************************//

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixed) {
	ostream << fixed.toFloat();
	return (ostream);}