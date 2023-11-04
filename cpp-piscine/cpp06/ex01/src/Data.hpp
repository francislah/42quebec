#ifndef	DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {
public:
//Default constructor (Required)
	Data(void);
//Copy constructor (Required)
	Data (const Data &copy );
//Constructors
//Default Destructor (Required)
	virtual ~Data();
//Destructors
//Copy assignment operator (Required)
	Data & operator = (const Data &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	uintptr_t	serialize(Data* ptr);

	Data*	deserialize(uintptr_t raw);

	friend	std::ostream& operator<<(std::ostream& out, const Data& Data);

protected:
private:
	int	x;
	int	y;
};

#endif