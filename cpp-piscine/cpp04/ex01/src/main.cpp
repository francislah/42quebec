#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void) {
	Animal *animals[10];
	Animal *copy;

	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {animals[i] = new Dog();}
		else {animals[i] = new Cat();}
		std::cout << i << ": " << animals[i]->getType() << std::endl;
		std::cout << std::endl;}
	copy = animals[0];
	std::cout << "copy :" << copy->getType() << " vs original: " << animals[0]->getType() << std::endl;
	for (int i = 0; i < 3; i++) {
		animals[i] = animals[i + 1];
		std::cout << i << ": " << animals[i]->getType() << std::endl;}
	std::cout << "copy :" << copy->getType() << " vs original: " << animals[0]->getType() << std::endl;
	for (int i = 0; i < 3; i++) {delete animals[i]; std::cout << std::endl;}
	delete copy;

}