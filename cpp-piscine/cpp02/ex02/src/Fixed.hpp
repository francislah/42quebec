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
	Fixed	operator+ (const Fixed &fixed) const;
	Fixed	operator- (const Fixed &fixed) const;
	Fixed	operator* (const Fixed &fixed) const;
	Fixed	operator/ (const Fixed &fixed) const;
	Fixed	&operator++( void );
	Fixed	&operator--( void );
	Fixed	operator++( int );
	Fixed	operator--( int );
	bool	operator<(const Fixed &fixed) const;
	bool	operator<= (const Fixed &fixed) const;
	bool	operator> (const Fixed &fixed) const;
	bool	operator >= (const Fixed &fixed) const;
	bool	operator == (const Fixed &fixed) const;
	bool	operator != (const Fixed &fixed) const;
//Swap function
//Setters & Getters
	void	setRawBits( int const raw );
	int		getRawBits( void ) const;
//Other functions
	int		toInt( void ) const;
	float	toFloat( void ) const;
	static Fixed		&min(Fixed &fixed1, Fixed &fixed2);
	static Fixed		&max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
	static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);

	private:
		int					_fixed_point_number;
		static const int	_n_fractional_bits = 8;
};

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixed);

#endif