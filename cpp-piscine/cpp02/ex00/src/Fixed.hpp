#ifndef CPP02_EX00_FIXED_HPP
# define CPP02_EX00_FIXED_HPP

#include <iostream>

class Fixed{
public:
//Default constructor (Required)
	Fixed ( void );
//Copy constructor (Required)
	Fixed (const Fixed &fixed );
//Constructors
//Default Destructor (Required)
	~Fixed ( void );
//Destructors
//Copy assignment operator (Required)
	Fixed & operator = (const Fixed &fixed);
//Operators
//Swap function
//Other functions

	void	setRawBits( int const raw );
	int		getRawBits( void ) const;


private:
	int					_fixed_point_number;
	static const int	_n_fractional_bits = 8;
};

#endif