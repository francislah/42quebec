# include "RPN.hpp"
/*
RPN can be evaluated using a stack data structure.
To evaluate an RPN expression, we start by pushing the operands onto the stack,
and when we encounter an operator, we pop the top two operands off the stack,
apply the operator to them, and push the result back onto the stack.
We continue this process until the expression is fully evaluated
and there is only one element left on the stack, which is the result of the expression.
*/

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cout << "Error: execute as " << *argv << " \"Polish mathematical expression\"" << std::endl;
		return 1;}
	RPN input(argv[1]);
	if (input.isValid()) {
		input.execute_expression();
		}
	
	return 0;
}
