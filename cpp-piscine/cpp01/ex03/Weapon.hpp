#ifndef CPP01_EX03_WEAPON_HPP
# define CPP01_EX03_WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		std::string const &	getType( void ) const;
		void			setType( std::string newType );

		Weapon( std::string Type );
		~Weapon( void );
};

#endif