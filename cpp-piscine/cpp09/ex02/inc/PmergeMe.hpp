#ifndef PmergeMe_HPP
 #define PmergeMe_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <sys/time.h>
# include <iomanip>

class PmergeMe {
public:
//Default constructor (Required)
	PmergeMe();
//Copy constructor (Required)
	PmergeMe (const PmergeMe &copy);
//Constructors
	PmergeMe(const int, const char **);
//Default Destructor (Required)
	~PmergeMe();
//Destructors
//Copy assignment operator (Required)
	PmergeMe & operator = (const PmergeMe &copy);
//Operators
//Swap function
//Setters & Getters
	size_t getSize() const;
//Other functions
	void	printBeforeVec() const;
	void	printAfterVec() const;

	void	printBeforeDeque() const;
	void	printAfterDeque() const;

	void	printVectorTime() const;
	void	printDequeTime() const;

	void	vectorSortTimer();
	void	dequeSortTimer();

	bool isValid() const;
protected:

private:
	bool valid_;
	size_t n;
	std::vector<int> vec;
	std::deque<int>	deque;
	size_t K;
	double vecTime;
	double dequeTime;

	void	vectorSort(size_t start, size_t end);
	void	vectorInsertionSort(size_t start, size_t end);
	void	vectorMerge(size_t start, size_t middle, size_t end);
	
	void	dequeSort(size_t start, size_t end);
	void	dequeInsertionSort(size_t start, size_t end);
	void	dequeMerge(size_t start, size_t middle, size_t end);
};

#endif