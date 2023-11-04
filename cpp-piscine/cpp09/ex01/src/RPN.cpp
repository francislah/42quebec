#include "RPN.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

RPN::RPN(void) {}

RPN::RPN(const char *expr)  {
	std::stack<std::string> tmp = split_expression(expr);
	valid_ = validate_expression(tmp);
}

RPN::RPN(const RPN &copy) {
	*this = copy;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

bool RPN::isValid() {return (valid_);}

void RPN::execute_expression() {
	if (!valid_) {
		std::cout << "Error: expression not valid." << std::endl;
		return;}
	std::stack<long> pol;
	while (!rpn.empty()) {
		std::string tmp = rpn.top();
		rpn.pop();
		if (strchr("0123456789", tmp[0])) {
			pol.push(std::stoi(tmp));}
		else if (strchr("-+/*", tmp[0]) && pol.size() > 1) {
			long n1 = pol.top();
			pol.pop();
			long n2 = pol.top();
			pol.pop();
			char c = tmp[0];
			switch (c) {
				case '/':
					pol.push(n2 / n1);
					break;
				case '*':
					pol.push(n2 * n1);
					break;
				case '+':
					pol.push(n2 + n1);
					break;
				case '-':
					pol.push(n2 - n1);;
					break;}
		}
		else {
			std::cout << "Error: expression not valid. ";
			std::cout << "Not enough numbers in stack at \"";
			std::cout << tmp << "\"" << std::endl;
			valid_ = 0;
			return;
		}
	}
	print(pol);
}

bool	RPN::validate_expression(std::stack<std::string> invert) {
	while (!invert.empty()) {
		std::string tmp = invert.top();
		invert.pop();
 		if (tmp.size() != 1 || !strchr("-+/*0123456789", tmp[0])) {
			std::cout << "Error: wrong parameter in expression (" << tmp << ")" << std::endl;
			return false;}
		else {
			rpn.push(tmp);}
	}
	return true;
}

std::stack<std::string>	RPN::split_expression(const char *expr) {
	std::stack<std::string> tmp;

	while (*expr) {
		while (*expr == ' ') {
			expr++;}
		const char *word_end = expr;
		while (*word_end && *word_end != ' ') {
			word_end++;}
		if (expr != word_end) {
			tmp.push(std::string(expr, word_end - expr));}
		expr = word_end;
	}
	return (tmp);
}

void	RPN::print(std::stack<long> pol) {
	int size = pol.size();
	long tmp[size];
	for (size_t i = 0; !pol.empty(); i++) {
		tmp[i] = pol.top();
		pol.pop();}
	while (--size >= 0) {
		std::cout << tmp[size] << " ";}
	std::cout << std::endl;
}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

RPN &RPN::operator=(const RPN &copy){
	if (this != &copy){
		valid_ = copy.valid_;
		rpn = copy.rpn;}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

RPN::~RPN(void){}