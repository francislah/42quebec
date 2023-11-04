#include "BitcoinExchange.hpp"
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: Execute as \""<< *argv << " <file>\"." << std::endl;
		return 1;}
	BitcoinExchange btc("data.csv", argv[1]);
	if (btc.validate() == false) {return (2);}
	btc.get_rate_data();
	if (btc.validate() == false) {return (2);}
	btc.get_input_data();
	btc.print_output();
	return 0;
}
