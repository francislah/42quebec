#include <iostream>
#include <cstddef>
#include "Data.hpp"


//uintptr_t	serialize(Data* ptr) {return (reinterpret_cast<uintptr_t>(ptr));}

//Data*	deserialize(uintptr_t raw) {return (reinterpret_cast<Data*>(raw));}

int	main(void) {
	Data 		data;
	uintptr_t	serialized;
	Data*		deserialized = NULL;

	serialized = deserialized->serialize(&data);
	deserialized = deserialized->deserialize(serialized);
	std::cout << serialized << " vs " << deserialized << std::endl;
	if (deserialized == &data) {
		std::cout << "success" << std::endl;}
	else {
		std::cout << "failure" << std::endl;}
	if (++deserialized == &data) {
		std::cout << "success" << std::endl;}
	else {
		std::cout << "failure" << std::endl;}
}