#ifndef RPN_HPP
 #define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>

class RPN {
public:
//Default constructor (Required)
	RPN();
//Copy constructor (Required)
	RPN (const RPN &copy);
//Constructors
	RPN(const char *expr);
//Default Destructor (Required)
	~RPN();
//Destructors
//Copy assignment operator (Required)
	RPN & operator = (const RPN &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	void print(std::stack<long>);
	std::stack<std::string> split_expression(const char *);
	bool	validate_expression(std::stack<std::string>);
	void	execute_expression();

	bool isValid();

protected:

private:
	bool valid_;
	std::stack<std::string> rpn;
};

#endif