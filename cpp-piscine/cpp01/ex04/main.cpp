#include <iostream>
#include <fstream>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Error: execute as ./replace file_name str_find str_replace" << std::endl;
		return (1);
	}
	std::ifstream	infile;
	infile.open(argv[1]);
	if (infile.is_open() == false) {
		std::cout << "Error: couldn't open file" << argv[1] << std::endl;
		return (1);
	}
	std::ofstream	outfile;
	outfile.open((std::string)argv[1] + ".replace");
	if (outfile.is_open() == false) {
		std::cout << "Error: couldn't open file" << argv[1] << std::endl;
		infile.close();
		return (1);
	}
	int			index;
	std::string	line;
	std::string newline;
	getline(infile, line);
	while (line.empty() == false) {
		while ((index = line.find((std::string)argv[2])) != -1) {
			newline = line.substr(0, index);
			outfile << newline;
			outfile << (std::string)argv[3];
			line.erase(0, index + strlen(argv[2]));
		}
		outfile << line << "\n";
		getline(infile, line);
	}
	return (0);
}