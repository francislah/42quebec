#ifndef ARRAY_HPP
 #define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array {
public:
//Default constructor (Required)
Array() : _data(NULL), _size(0) {}
//Copy constructor (Required)
Array (const Array<T> &copy) : _data(new T[copy.size]), _size(copy.size) {
	for (unsigned int i = 0; i < copy.size; i++) {
		_data[i] = copy._data[i];}
}
//Constructors
Array(unsigned int n) : _data(new T[n]()), _size(n) {}
//Default Destructor (Required)
~Array() {delete [] _data;}
//Destructors
//Copy assignment operator (Required)
Array<T> & operator = (const Array<T> &copy) {
	if (this != copy) {
		delete[] _data;
		_data = new T[copy._size];
		_size = copy._size;
		for (unsigned int i = 0; i < copy._size; i++) {
			_data[i] = copy._data[i];}
	}
	return (*this);};
//Operators
T	&operator[](unsigned int index) {
	if (index >= this->_size) {
		throw std::out_of_range("Array index is out of bounds");}
	return (_data[index]);}
//Swap function
//Setters & Getters
	unsigned int	size() const {return (_size);}
//Other functions
//Variables
protected:
private:
	T*				_data;
	unsigned int	_size;
};

#endif
