#include "PmergeMe.hpp"

//**************************************************************************//
//                              Constructors                                //
//**************************************************************************//

PmergeMe::PmergeMe(void) : valid_(false), n(0), K(2), dequeTime(0) {}

PmergeMe::PmergeMe(const int argc, const char **args) : valid_(false), n(argc - 1), K(2), dequeTime(0) {
	if (!args || argc < 2) {
		return;}
	for (size_t i = 0; args[i]; i++) {
		for (size_t j = 0; args[i][j]; j++) {
			if (!strchr("0123456789", args[i][j])) {
				return;}
		}
		if (strlen(args[i]) > 11 || std::stod(args[i]) > INT_MAX) {
			return;}
		vec.push_back(std::stoi(args[i]));
		deque.push_back(std::stoi(args[i]));
	}
	valid_ = true;
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;}

//**************************************************************************//
//                                 Setters                                  //
//**************************************************************************//

//**************************************************************************//
//                                 Getters                                  //
//**************************************************************************//

size_t	PmergeMe::getSize() const {return n;}

//**************************************************************************//
//                             Member functions                             //
//**************************************************************************//

bool	PmergeMe::isValid() const {return valid_;}

void	PmergeMe::printBeforeVec() const {
	std::cout << "Before (std::vector): ";
	std::vector<int>::const_iterator it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " ";
		++it;}
	std::cout << std::endl;
}

void	PmergeMe::printBeforeDeque() const {
	std::cout << "Before (std::deque): ";
	std::deque<int>::const_iterator it = deque.begin();
	while (it != deque.end()) {
		std::cout << *it << " ";
		++it;}
	std::cout << std::endl;
}

void	PmergeMe::printAfterVec() const {
	std::cout << "After (std::vector): ";
	std::vector<int>::const_iterator it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " ";
		++it;}
	std::cout << std::endl;
}

void	PmergeMe::printAfterDeque() const {
	std::cout << "After (std::deque):  ";
	std::deque<int>::const_iterator it = deque.begin();
	while (it != deque.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void	PmergeMe::printVectorTime() const {
	std::cout << std::fixed;
	std::cout <<  std::setprecision(8);
	std::cout << "Time to process a range of " << n << " elements with std::vector<int> : ";
	std::cout << vecTime * 1000 << " us" << std::endl;
}

void	PmergeMe::printDequeTime() const {
	std::cout << std::fixed;
	std::cout <<  std::setprecision(8);
	std::cout << "Time to process a range of " << n << " elements with std::deque<int> : ";

	std::cout << dequeTime * 1000 << " us" << std::endl;
}

void	PmergeMe::vectorMerge(size_t start, size_t middle, size_t end) {
    size_t i = start;
    size_t j = middle + 1;
    size_t k = start;
	std::vector<int> temp(n);
    while ((i <= middle) && (j <= end)) {
        if (vec[i] < vec[j]) {temp[k] = vec[i++];}
        else {temp[k] = vec[j++];}
        k++;}
    for (; j <= end; j++, k++) {temp[k] = vec[j];}
	for (; i <= middle; i++, k++) {temp[k] = vec[i];}
	for (i = start; i <= end; i++) {vec[i] = temp[i];}
}

void	PmergeMe::vectorInsertionSort(size_t start, size_t end) {
	for (size_t i = start; i < end; i++) {
		int tmp = vec[i + 1];
		size_t j = i + 1;
		while (j > start && vec[j - 1] > tmp) {
			vec[j] = vec[j - 1];
			j--;}
		vec[j] = tmp;}	
}

void	PmergeMe::vectorSort(size_t start, size_t end) {
	if (start < end) {
		if ((end - start) > K) {
			int middle = (start + end) / 2;
			vectorSort(start, middle);
			vectorSort(middle + 1, end);
			vectorMerge(start, middle, end);}
		else {
			vectorInsertionSort(start, end);}
	}
} 

void	PmergeMe::vectorSortTimer() {
	static struct timeval begin;
	static struct timeval end_time;

	gettimeofday(&begin, 0);
	vectorSort(0, getSize() - 1);
	gettimeofday(&end_time, 0);
	long seconds = end_time.tv_sec - begin.tv_sec;
    long microseconds = end_time.tv_usec - begin.tv_usec;
    vecTime = seconds + microseconds*1e-6;
}

void	PmergeMe::dequeMerge(size_t start, size_t middle, size_t end) {
    size_t i = start;
    size_t j = middle + 1;
    size_t k = start;
	std::deque<int> temp(n);
    while ((i <= middle) && (j <= end)) {
        if (deque[i] < deque[j]) {temp[k] = deque[i++];}
        else {temp[k] = deque[j++];}
        k++;}
    for (; j <= end; j++, k++) {temp[k] = deque[j];}
	for (; i <= middle; i++, k++) {temp[k] = deque[i];}
	for (i = start; i <= end; i++) {deque[i] = temp[i];}
}

void	PmergeMe::dequeInsertionSort(size_t start, size_t end) {
	for (size_t i = start; i < end; i++) {
		int tmp = deque[i + 1];
		size_t j = i + 1;
		while (j > start && deque[j - 1] > tmp) {
			deque[j] = deque[j - 1];
			j--;}
		deque[j] = tmp;}	
}

void	PmergeMe::dequeSort(size_t start, size_t end) {
	if ((end - start) > K) {
		int middle = (start + end) / 2;
		dequeSort(start, middle);
		dequeSort(middle + 1, end);
		dequeMerge(start, middle, end);}
	else {
		dequeInsertionSort(start, end);}
}

void	PmergeMe::dequeSortTimer() {
	static struct timeval begin;
	static struct timeval end_time;

	gettimeofday(&begin, 0);
	dequeSort(0, getSize() - 1);
	gettimeofday(&end_time, 0);
	long seconds = end_time.tv_sec - begin.tv_sec;
    long microseconds = end_time.tv_usec - begin.tv_usec;
    dequeTime = seconds + microseconds*1e-6;
}

//**************************************************************************//
//                           Operators overload                             //
//**************************************************************************//

PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
	if (this != &copy){
		valid_ = copy.valid_;
		n = copy.n;
		vec.clear();
		vec = copy.vec;
		deque.clear();
		deque = copy.deque;
		K = copy.K;
		vecTime = copy.vecTime;
		dequeTime = copy.dequeTime;}
	return (*this);}

//**************************************************************************//
//                               Destructors                                //
//**************************************************************************//

PmergeMe::~PmergeMe(void){
	deque.clear();
	vec.clear();
}