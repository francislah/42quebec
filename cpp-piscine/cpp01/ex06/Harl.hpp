#ifndef CPP_EX05_HARL_HPP
# define CPP_EX05_HARL_HPP

#include <iostream>

class Harl
{
	private:
		void	insignificant( void );
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		void	complain( std::string level );
		Harl();
		~Harl();
};

#endif