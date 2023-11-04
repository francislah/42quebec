#pragma once
# include <iostream>
class Base {
	public:
		virtual ~Base() {};
		virtual char getType() const = 0;
};
class A: public Base {
	public:
		char getType() const {return ('A');}
};
class B: public Base {
	public:
		char getType() const {return ('B');}
};
class C: public Base {
	public:
		char getType() const {return ('C');}
};