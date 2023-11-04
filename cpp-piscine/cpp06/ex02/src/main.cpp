#include "Base.hpp"

Base	*generate(void) {srand(time(nullptr));
	switch (rand() % 3) {
		case 0: return (new A);
		case 1: return (new B);
		case 2: return (new C);}
	return (new A);
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p)) {std::cout << "A" << std::endl;}
	else if (dynamic_cast<B*>(p)) {std::cout << "B" << std::endl;}
	else if (dynamic_cast<C*>(p)) {std::cout << "C" << std::endl;}
}

void	identify(Base& p) {
	try {
		Base& compare = dynamic_cast<A&>(p);
		std::cout << compare.getType() << std::endl;}
	catch (std::exception &e){}
	try {
		Base& compare = dynamic_cast<B&>(p);
		std::cout << compare.getType() << std::endl;}
	catch (std::exception &e){}
	try {
		Base& compare = dynamic_cast<C&>(p);
		std::cout << compare.getType() << std::endl;}
	catch (std::exception &e){}
}

int	main(void) {
	Base	*p = generate();

	identify(p);
	identify(*p);
	delete (p);
	return (0);}