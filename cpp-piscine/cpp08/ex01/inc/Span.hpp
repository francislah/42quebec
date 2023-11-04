#ifndef SPAN_HPP
 #define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span {
public:
//Default constructor (Required)
Span();
//Copy constructor (Required)
Span (const Span &copy);
//Constructors
Span(unsigned int N);
//Default Destructor (Required)
~Span();
//Destructors
//Copy assignment operator (Required)
Span & operator = (const Span &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	void addNumber(int x);
	void addNumbers(std::vector<int> const &numbers);
	int shortestSpan() const;
	int longestSpan() const;
protected:

private:
	unsigned int N_;
	std::vector<int> storage_;
};

#endif