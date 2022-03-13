/*
*	Author: CS
*	Date:	2022_03_13
*
*	A simple list implementation with a range-checked bidirectional iterator, it's safe provided you don't erase the link
*	it points to.
* 
*	A list implementation with a range-checked bidirectional iterator, due to the lack of random access,
*	keeping a pointer to the list, along with its index, iterating back to meet the index each time would be an option
*	to avoid the scenario where the iterator's pointed to object has been deleted, however would be inefficient for access.
*	A static object, associating indexes and given pointers could also be used.
* 
*	(Edit of Ch20 Q13)
*/

#include <iostream>
#include "CS_list.h"

int main() {
	try{
		{
			list newlist(5);	// initializes a list with the number 5 as the first element
			newlist.erase(newlist.begin());
			newlist.push_front(8);
			newlist.push_front(80);
			newlist.back() = 50;
			newlist.insert(newlist.end(), 650);
			newlist.push_back(200);
			newlist.push_back(900);
			newlist.push_back(50);
			std::cout << "The list is as follows:\n";
			newlist.print();
			std::cout << "Testing the list with a function of STL style:\n";
			std::cout << "The highest is:\t" << *high(newlist.begin(), newlist.end()) << std::endl;
			std::cout << "Iterators with the list object work as expected.\n";

			try {
				std::cout << "\nTesting --list<int>::begin():\n";
				--newlist.begin();
			}
			catch (std::exception e)
			{
				std::cout << e.what() << std::endl;
			}
			try {
				std::cout << "\nTesting ++list<int>::end():\n";
				++newlist.end();
			}
			catch (std::exception e)
			{
				std::cout << e.what() << std::endl;
			}
			std::cout << "\nSetting the last value to 1000 using the dereference operator and rerunning^:\n";
			auto last = high(newlist.begin(), newlist.end());
			++last;
			*last = 1000;
			std::cout << "The list is as follows:\n";
			newlist.print();
			std::cout << "Testing the list with a function of STL style:\n";
			std::cout << "The highest is:\t" << *high(newlist.begin(), newlist.end()) << std::endl;
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}