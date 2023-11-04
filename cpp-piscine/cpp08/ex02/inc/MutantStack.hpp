#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
public:
//Default constructor (Required)
	MutantStack() {}
//Copy constructor (Required)
	MutantStack (const MutantStack &copy) {*this = copy;}
//Constructors
//Default Destructor (Required)
	~MutantStack() {}
//Destructors
//Copy assignment operator (Required)
	MutantStack & operator = (const MutantStack &copy) {
		if (this != &copy) {}
		return (*this);
	}
//Operators
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() {return (this->c.begin());};
	iterator end() {return (std::stack<T>::c.end());};
//Swap function
//Setters & Getters
//Other functions
protected:

private:
};

#endif