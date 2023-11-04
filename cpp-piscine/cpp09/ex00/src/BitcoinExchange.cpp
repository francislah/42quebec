#include "BitcoinExchange.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::string rate, std::string input)
	: rateFile_(rate),
	inputFile_(input),
	exchangeRate_(rate),
	input_(input) {
		if (verify_open()) {
			valid_ = 1;}
		else {valid_ = 0;}
	}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

bool BitcoinExchange::verify_open() {
	if (!exchangeRate_.is_open()) {
		std::cerr << "Error: Couldn't open database" << std::endl;
		exchangeRate_.close();
		return (false);
	} 
	else if (!input_.is_open()) {
		std::cerr << "Error: Couldn't open inputfile" << std::endl;
		input_.close();
		return (false);}
	return (true);
}

bool	BitcoinExchange::validate() {
	if (valid_) {
		return (true);}
	else {return (false);}
}

bool is_date(const std::string& date) {
	if (date.size() < 10) {
		return false;}
	for(size_t i = 0; i < date.size(); i++) {
        if(i == 4 || i == 7) { 
        	if (date[i] != '-') {
				return false;}
        }
		else if (!isdigit(date[i])) {
            return false;}
    }
	return true;
}

bool BitcoinExchange::is_int_float_input(const std::string &num) {
	try {
		double d = std::stod(num);
		if (d < 0 || num.find('+') != std::string::npos) {
			inputData_.push_back(std::make_pair("Error: not a positive number.", 0));
			return false;}
		if (d > 1000) {
			inputData_.push_back(std::make_pair("Error: too large a number.", 0));
			return false;}
		if (num.find('.') != std::string::npos) {
			try {std::stof(num);}
			catch (std::exception &e) {
				inputData_.push_back(std::make_pair("Error: not a valid float number.", 0));
				return false;}
		}
		return true;}
	catch(std::exception& e) {
        std::cerr << "Error: Invalid number format." << std::endl;
		return false;}
}

bool BitcoinExchange::is_int_float_rate(const std::string &num) {
	try {
		double d = std::stod(num);
		if (d < 0 || num.find('+') != std::string::npos) {
			std::cerr << "Error: database not valid" << std::endl; valid_ = 0;
			return false;}
		if (d > INT_MAX) {
			std::cerr << "Error: database not valid" << std::endl; valid_ = 0;
			return false;}
		if (num.find('.') != std::string::npos) {
			try {std::stof(num);}
			catch (std::exception &e) {
				std::cerr << "Error: database not valid" << std::endl; valid_ = 0;
				return false;}
		}
		return true;}
	catch(std::exception& e) {
        std::cerr << "Error: Invalid number format." << std::endl;
		return false;}
}

void	BitcoinExchange::get_input_data() {
	if (!valid_) {
		std::cerr << "Error: BitcoinExchange not valid." << std::endl;
		return;}
	std::string data;
	getline(input_, data);
	size_t date_pos = data.find("date");
	if (date_pos != std::string::npos) {
		size_t value_pos = data.find("value");
		std::string sep = data.substr(4, value_pos - 4);
		if (value_pos != std::string::npos) {
			while(getline(input_, data)) {
				std::string date_tmp;
				std::string rate_tmp;
				if (data.size() < 10) {
					inputData_.push_back(std::make_pair("Error: date invalid.", 0));}
				else {
					date_tmp = data.substr(date_pos, 10);
					if (is_date(date_tmp) == false) {
						inputData_.push_back(std::make_pair("Error: date invalid.", 0));}
					else if (data.size() > 9 && is_date(date_tmp) == true) {
						if (data.find(sep) != std::string::npos) {
							rate_tmp = data.substr(data.find(sep) + sep.size());
							if (is_int_float_input(rate_tmp)) {
								inputData_.push_back(std::make_pair(date_tmp, std::stod(rate_tmp)));}
						}
						else {
							inputData_.push_back(std::make_pair("Error: bad input => " + date_tmp, 0));
						}
					}
				}
			}
		}
		else {valid_ = 0; return;}
	}
	else {valid_ = 0; return;}
}

void	BitcoinExchange::get_rate_data() {
	if (!valid_) {
		std::cerr << "Error: BitcoinExchange not valid." << std::endl;
		return;}
	std::string data;
	getline(exchangeRate_, data);
	size_t date_pos = data.find("date");
	if (date_pos != std::string::npos) {
		size_t value_pos = data.find("exchange_rate");
		std::string sep = data.substr(4, value_pos - 4);
		if (value_pos != std::string::npos) {
			while(getline(exchangeRate_, data)) {
				std::string date_tmp;
				std::string rate_tmp;
				if (data.size() < 10) {
					std::cerr << "Error: database not valid" << std::endl; valid_ = 0; return;}
				else {
					date_tmp = data.substr(date_pos, 10);}
				if (is_date(date_tmp) == false) {
					std::cerr << "Error: database not valid" << std::endl; valid_ = 0; return;}
				else if (data.size() > 9 && is_date(date_tmp) == true) {
					if (data.find(sep) != std::string::npos) {
						rate_tmp = data.substr(data.find(sep) + sep.size());
						if (is_int_float_rate(rate_tmp)) {
							rateData_.push_back(std::make_pair(date_tmp, std::stod(rate_tmp)));}
					}
					else {
						std::cerr << "Error: database not valid" << std::endl; valid_ = 0; return;
					}
				}
			}
		}
		else {valid_ = 0; return;}
	}
	else {valid_ = 0; return;}
}

void	BitcoinExchange::print_input_list() {
	std::list< std::pair<std::string, double> >::iterator it;
	std::list< std::pair<std::string, double> >::iterator it_end = inputData_.end();
    for (it = inputData_.begin(); it != it_end; ++it) {
		std::cout << (*it).first << ": " << (*it).second << std::endl;}
}

void	BitcoinExchange::print_rate_list() {
	std::list< std::pair<std::string, double> >::iterator it;
	std::list< std::pair<std::string, double> >::iterator it_end = rateData_.end();
    for (it = rateData_.begin(); it != it_end; ++it) {
		std::cout << (*it).first << ": " << (*it).second << std::endl;}
}

double date_to_double(const std::string &date) {
	double ret = 0;
	ret += (date[0] - 48) * 10000000;
	ret += (date[1] - 48) * 1000000;
	ret += (date[2] - 48) * 100000;
	ret += (date[3] - 48) * 10000;
	ret += (date[5] - 48) * 1000;
	ret += (date[6] - 48) * 100;
	ret += (date[8] - 48) * 10;
	ret += (date[9] - 48) * 1;
	return ret;
}

bool isValidDate(const std::string& date_str) {
    std::tm date = {};
	std::istringstream ss(date_str);
	if (ss >> std::get_time(&date, "%Y-%m-%d")) {
		// Check if date is greater than today
		std::time_t now = std::time(nullptr);
		std::tm today = *std::localtime(&now);
		if (std::mktime(&date) > std::mktime(&today)) {
			return false;}
		// Check if date is valid
		std::ostringstream oss;
		oss << std::put_time(&date, "%Y-%m-%d");
		if (oss.str() != date_str) {
			return false;}
		return true;}
	else {
		return false;}
}

void BitcoinExchange::print_output() {
	for (std::list< std::pair<std::string, double> >::iterator itInput = inputData_.begin(); itInput != inputData_.end(); ++itInput) {
		if (!isValidDate((*itInput).first)) {
			std::cout << "Error: bad input => " << (*itInput).first << std::endl;}
		else {
			double dateInput = date_to_double((*itInput).first);
			for (std::list< std::pair<std::string, double> >::iterator itRate = rateData_.begin(); itRate != rateData_.end(); ) {
				if (dateInput < date_to_double((*itRate).first) && itRate == rateData_.begin()) {
					std::cout << "Error: bad input => " << (*itInput).first << std::endl;
					break;}
				if (dateInput < date_to_double((*itRate).first) && itRate != rateData_.begin()) {
					double result = (*itInput).second * (*--itRate).second;
					std::cout << (*itInput).first << " => " << (*itInput).second << " = " << result << std::endl;
					break;}
				if (++itRate == rateData_.end()) {
					double result = (*itInput).second * (*--itRate).second;
					std::cout << (*itInput).first << " => " << (*itInput).second << " = " << result << std::endl;
					break;}
			}
		}
	}
}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy){
	if (this != &copy){
		exchangeRate_.close();
		exchangeRate_.open(copy.rateFile_);
		input_.close();
		input_.open(copy.inputFile_);
		rateData_.clear();
		rateData_ = copy.inputData_;
		inputData_.clear();
		inputData_ = copy.inputData_;
		valid_ = copy.valid_;}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

BitcoinExchange::~BitcoinExchange(void){
	input_.close();
	exchangeRate_.close();
	inputData_.clear();
	rateData_.clear();
}