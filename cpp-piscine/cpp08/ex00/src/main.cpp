# include "../inc/easyfind.hpp"

int main() {
    std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
    std::vector<int>::iterator it = easyfind(v, 3);
	if (it != v.end()) {
   		std::cout << "Value found at position: " << (it - v.begin()) << std::endl;}
	else {std::cout << "Value found at position: none" << std::endl;}
	it = easyfind(v, 20);
    if (it != v.end()) {
        std::cout << "Value found at position: " << (it - v.begin()) << std::endl;}
	else {std::cout << "Value found at position: none" << std::endl;}
    return 0;}
