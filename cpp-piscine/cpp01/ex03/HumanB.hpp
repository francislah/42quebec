#ifndef CPP01_EX03_HUMANB_HPP
# define CPP01_EX03_HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon 		*_weapon;

	public:
		void	attack( void ) const;
		void	setWeapon( Weapon &weaponType);

		HumanB( std::string name );
		~HumanB( void );
};

#endif