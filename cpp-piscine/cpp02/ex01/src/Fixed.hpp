#ifndef CPP02_EX01_FIXED_HPP
#define CPP02_EX01_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
public:
//Default constructor (Required)
	Fixed ( void );
//Copy constructor (Required)
	Fixed (const Fixed &fixed );
//Constructors
	Fixed ( const int num );
	Fixed ( const float num );
//Default Destructor (Required)
	~Fixed ( void );
//Destructors
//Copy assignment operator (Required)
	Fixed & operator = (const Fixed &fixed);
//Operators
//Swap function
//Setters & Getters
	void	setRawBits( int const raw );
	int		getRawBits( void ) const;
//Other functions
	int		toInt( void ) const;
	float	toFloat( void ) const;

private:
	int					_fixed_point_number;
	static const int	_n_fractional_bits = 8;
};

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixed);

#endif