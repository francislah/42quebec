#ifndef CPP01_EX00_ZOMBIE_HPP
# define CPP01_EX00_ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie ( std::string name );
		Zombie( void );
		~Zombie();

		void	announce( void );
		void	setName( std::string name );
};

Zombie*	zombieHorde( int N, std::string name);

#endif