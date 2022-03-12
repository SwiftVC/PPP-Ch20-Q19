/*
*	Author: CS
*	Date:	2022_03_12
*
*	This is a recreation of the STL list (working back from the user interface) like the STL where it manages it's own memory as opposed to the
*	pointer handling of previous chapters.
*	It's been left in non-generalized integer element form for readability.
*	+ve the list works when reduced to nothing and grown again, the memory is properly deallocated.
* 
*	Criticism:
*	The iterator used for list is not declared in the namespace of the list interface but in the list_node and so the user sees an unintuitive naming convention
*	for iterators.
*	No structured testing procedure was made for this more complicated environment.
* 
*	Lesson:
*	When testing the non-templated version, the methods should be in a standard, non-header file
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
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}