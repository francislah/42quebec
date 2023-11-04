#include <iostream>
#include <cmath>
#include <limits>

void	printFromChar(char c) {
	if (std::isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;}
	else {std::cout << "char: Non displayable" << std::endl;}
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printFromInt(int i, std::string conv) {
	for (int i = 0; conv[i]; i++) {
		if (!std::isdigit(conv[i])){
			std::cout << "Error: Parameter is not a literal" << std::endl;
			return;}
	}
	if (i >= 0 && i <= 127 && std::isprint(static_cast<char>(i))) {
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;}
	else if (i >= 0 && i <= 127) {std::cout << "char: Non displayable" << std::endl;}
	else {std::cout << "char: impossible" << std::endl;}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	printFromDouble(double d, std::string conv) {
	for (int i = 0; conv[i]; i++) {
		if (!std::isdigit(conv[i]) && conv[i] == '.'){
			for (++i; conv[i]; i++) {
				if (!std::isdigit(conv[i])) {
					std::cout << "Error: Parameter is not a literal" << std::endl;
					return;}
			}
		}
	}
	if (d >= 0 && d <= 127 && std::isprint(static_cast<char>(d))) {
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;}
	else if (d >= 0 && d <= 127) {std::cout << "char: Non displayable" << std::endl;}
	else {std::cout << "char: impossible" << std::endl;}
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max()) {
		std::cout << "int: " << static_cast<int>(d) << std::endl;}
	else {std::cout << "int: impossible" << std::endl;}
	if (std::isinf(static_cast<float>(d))) {
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;}
	else if (static_cast<float>(d) == static_cast<int>(d)) {
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;}
	else {std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;}
	if (static_cast<int>(d) == d) {std::cout << "double: " << d << ".0" << std::endl;}
	else {std::cout << "double: " << d << std::endl;}
}

void	printFromFloat(float f, std::string conv) {
	for (int i = 0; conv[i]; i++) {
		if (!std::isdigit(conv[i]) && conv[i] == '.'){
			for (++i; conv[i]; i++) {
				if (!std::isdigit(conv[i]) && conv[i] != 'f') {
					std::cout << "Error: Parameter is not a literal" << std::endl;
					return;}
				else if (conv[i] == 'f' && conv.size() - 1 != (size_t)i) {
					std::cout << "Error: Parameter is not a literal" << std::endl;
					return;}
			}
		}
	}
	if (f >= 0 && f <= 127 && std::isprint(static_cast<char>(f))) {
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;}
	else if (f >= 0 && f <= 127) {std::cout << "char: Non displayable" << std::endl;}
	else {std::cout << "char: impossible" << std::endl;}
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max()) {
		std::cout << "int: " << static_cast<int>(f) << std::endl;}
	else {std::cout << "int: impossible" << std::endl;}
	if (f == static_cast<int>(f)) {
		std::cout << "float: " << f << ".0f" << std::endl;}
	else {std::cout << "float: " << f << "f" << std::endl;}
	if (static_cast<int>(f) == static_cast<double>(f)) {
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;}
	else {std::cout << "double: " << static_cast<double>(f) << std::endl;}
}

void	printFromNan() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	printFromInf(std::string inf) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << inf << "f" << std::endl;
	std::cout << "double: " << inf << std::endl;
}

//Char '0' parce que sinon 0 pris en compte comme char
int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Invalid number of arguments. Please provide a single literal." << std::endl;
		return 1;}
	std::string conv = argv[1];
	if (conv == "nan" || conv == "nanf") {
		printFromNan(); return 0;}
	else if (conv == "-inf" || conv == "inf") {
		printFromInf(conv); return 0;}
	else if (conv.length() == 3 && conv[0] == '\'' && conv[2] == '\''){
		printFromChar(conv[1]);}
	else if (std::strchr(conv.c_str(), '.') != NULL && std::strchr(conv.c_str(), 'f')) {
		float f;
		try {f = std::stof(conv);}
		catch (const std::exception &e) {
			std::cout << "Error: Parameter is not a literal" << std::endl;
			return (1);}
		printFromFloat(f, conv);}
	else if (std::strchr(conv.c_str(), '.') != NULL) {
		double d;
		try {d = std::stod(conv);}
		catch (const std::exception &e) {
			std::cout << "Error: Parameter is not a literal" << std::endl;
			return (1);}
		printFromDouble(d, conv);
	}
	else {
		double d;
		try {d = std::stod(conv);}
		catch (const std::exception &e) {
			std::cout << "Error: Parameter is not a literal" << std::endl;
			return (1);}
		int	i;
		try {i = std::stoi(conv);}
		catch (const std::exception &e) {
			printFromDouble(d, conv);
			return (0);}
		printFromInt(i, conv);}
	return (0);
}