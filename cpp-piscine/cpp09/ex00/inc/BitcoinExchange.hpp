#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <list>
# include <utility>
# include <limits.h>
# include <stdio.h>

class BitcoinExchange {
public:
//Default constructor (Required)
	BitcoinExchange();
//Copy constructor (Required)
	BitcoinExchange (const BitcoinExchange &copy);
//Constructors
	BitcoinExchange(std::string data, std::string rate);
//Default Destructor (Required)
	~BitcoinExchange();
//Destructors
//Copy assignment operator (Required)
	BitcoinExchange & operator = (const BitcoinExchange &copy);
//Operators
//Swap function
//Setters & Getters
//Other functions
	bool validate();
	void get_rate_data();
	void get_input_data();
	void print_input_list();
	void print_rate_list();
	void print_output();
private:
	std::string rateFile_;
	std::string inputFile_;
	std::ifstream exchangeRate_;
	std::ifstream input_;
	std::list<std::pair<std::string, double> > inputData_;
	std::list<std::pair<std::string, double> > rateData_;
	int			valid_;

	bool verify_open();
	bool is_int_float_rate(const std::string &num);
	bool is_int_float_input(const std::string &num);
};

#endif