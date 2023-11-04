# include "../inc/Span.hpp"
# include <cstdlib>
# include <ctime>

int	main(void) {
	Span s = Span(5);

	s.addNumber(6);
	s.addNumber(3);
	s.addNumber(17);
	s.addNumber(9);
	s.addNumber(11);
	std::cout << s.shortestSpan() << std::endl;
	std::cout << s.longestSpan() << std::endl << std::endl;

	Span sp = Span(100000);
	std::srand(std::time(nullptr));
	for (int i = 0; i < 25000; i++) {
		sp.addNumber(std::rand() % 100);}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;

	Span a;

	try {a.shortestSpan();}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;}
	return 0;
}