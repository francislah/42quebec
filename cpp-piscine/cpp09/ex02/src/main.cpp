#include "PmergeMe.hpp"

/*brew install coreutils*/
/* ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "` */

/*Merge sort positive integers*/
int main(int argc, char const *argv[])
{
	PmergeMe list(argc, ++argv);

	if (list.isValid()) {
		list.printBeforeVec();
		list.vectorSortTimer();
		list.printAfterVec();
		list.printVectorTime();
		std::cout << std::endl;
		list.printBeforeDeque();
		list.dequeSortTimer();
		list.printAfterDeque();
		list.printDequeTime();
	}
	else {std::cout << "Error" << std::endl;}
	return 0;
}
