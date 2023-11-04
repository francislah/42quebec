#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {
	Animal a;
	Cat		b;
	Dog		c;
	Animal	*tbd = new Cat();
	WrongAnimal	*cat = new WrongCat();
	WrongCat	good;

	a.makeSound();
	std::cout << a.getType() << std::endl;
	b.makeSound();
	std::cout << b.getType() << std::endl;
	c.makeSound();
	std::cout << c.getType() << std::endl;
	tbd->makeSound();
	std::cout << tbd->getType() << std::endl;
	std::cout << "Bad inheritance: "; cat->makeSound();
	std::cout << cat->getType() << std::endl;
	std::cout << "Should have been: "; good.makeSound();
	std::cout << good.getType() << std::endl;
	delete(tbd);
	delete(cat);
}