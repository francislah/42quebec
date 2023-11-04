# include "../inc/Span.hpp"
//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

Span::Span(void) {}
Span::Span(unsigned int N) : N_(N) {}
Span::Span(const Span &copy) : N_(copy.N_), storage_(copy.storage_) {}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

void	Span::addNumber(int x) {
	if (storage_.size() == N_) {
		throw std::length_error("Storage is full");}
	storage_.push_back(x);}

void	Span::addNumbers(std::vector<int> const &numbers) {
	std::vector<int>::const_iterator i = numbers.begin();
	while (i != numbers.end()) {
		addNumber(*i);
		i++;}
}
	

int	Span::shortestSpan() const {
	if (storage_.size() < 2) {
		throw std::logic_error("No span can be found (size < 2)");}
	std::vector<int> sortedStorage(storage_);
	std::sort(sortedStorage.begin(), sortedStorage.end());
	int minSpan = sortedStorage[1] - sortedStorage[0];
	for (unsigned int i = 1; i < sortedStorage.size() - 1; i++) {
		int currentSpan = sortedStorage[i + 1] - sortedStorage[i];
		minSpan = std::min(minSpan, currentSpan);}
	return (minSpan);
}

int	Span::longestSpan() const {
	if (storage_.size() < 2) {
		throw std::logic_error("No span can be found (size < 2)");}
	int min = *std::min_element(storage_.begin(), storage_.end());
	int max = *std::max_element(storage_.begin(), storage_.end());
	return (max - min);
}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

Span &Span::operator=(const Span &copy){
	if (this != &copy){
		N_ = copy.N_;
		storage_ = copy.storage_;}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

Span::~Span(void){}