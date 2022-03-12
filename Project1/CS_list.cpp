#include "CS_list.h"

list_node* list::get_node(list_node::iterator p) {
	list_node* temp = front_ptr;
	list_node::iterator temp_iter = list_node::iterator(temp);
	int error_check{ 0 };
	while (temp_iter != p)
	{
		temp = temp->_next();
		++temp_iter;
		++error_check;
		if (error_check > size)
			throw std::exception("Invalid iterator passed to list.erase(..)");
	}
	return temp;
}

void list::push_back(int i) {
	list_node* temp = new list_node(i);
	list_node* second_last = get_node(last());
	temp->_head = second_last;
	temp->_tail = nullptr;
	if (second_last)	// case where push_back called for empty list
		second_last->_tail = temp;
	else
		front_ptr = temp;
	size++;
}

void list::push_front(int i) {
	list_node* temp = new list_node(i);
	temp->_head = nullptr;
	temp->_tail = front_ptr;
	if (front_ptr)		// case where push_back called for empty list
		front_ptr->_head = temp;
	front_ptr = temp;
	size++;
}

void list::print() { // for testing
	// creates an iterator and outputs each val on a newline
	if (size == 0)
	{
		std::cout << "empty list" << std::endl;
		return;
	}
	auto it = list_node::iterator(front_ptr);
	std::cout << *it << std::endl;
	while (it != nullptr) {
		++it;
		if (it != nullptr)
			std::cout << *it << std::endl;
	}
}

list_node::iterator list::insert(list_node::iterator p, const int& v) {
	// no entries - return nullptr
	if (size == 0)
		return nullptr;
	// insert at front
	if (p == list_node::iterator(front_ptr)) {
		push_front(v);
		return list_node::iterator(front_ptr);
	}
	// insert between two entries
	if (p!=end()) {
		list_node* temp = new list_node{ v };
		list_node* node_after_insertion = get_node(p);
		list_node* node_before_insertion = node_after_insertion->_head;
		node_before_insertion->_tail = temp;
		temp->_head = node_before_insertion;
		temp->_tail = node_after_insertion;
		node_after_insertion->_head = temp;
		size++;
		return list_node::iterator(temp);
	}
	else if(p==end()) {
		list_node* temp = new list_node{ v };
		list_node* last_node = get_node(last());
		temp->_tail = nullptr;
		temp->_head = last_node;
		last_node->_tail = temp;
		size++;
		return list_node::iterator(temp);
	}
	throw std::exception("Uncaught insert iterator");
}

list_node::iterator list::erase(list_node::iterator p) {		// used to handle all list deleting
	//no entries
	if (size == 0)
		return nullptr;
	// only entry
	else if (list_node::iterator(front_ptr) == p && !(*front_ptr)._tail)
	{
		delete front_ptr;
		front_ptr = nullptr;
		size--;
		return nullptr;
	}
	// first in list
	else if (list_node::iterator(front_ptr) == p) {
		auto temp = front_ptr->_next();
		front_ptr = front_ptr->_next();
		delete temp;
		size--;
		return list_node::iterator(front_ptr);
	}
	// from second to end
	else {
		// skip to match iterator
		list_node* temp = get_node(p);
		// set previous
		list_node* before_temp = (*temp)._prev();
		before_temp->_tail = temp->_next();
		if (temp->_next() != nullptr)
		{
			list_node* after_temp = (*temp)._next();
			after_temp->_head = before_temp;
		}
		delete temp;
		size--;
		return list_node::iterator(before_temp);
	}
}

list_node::iterator list::last()
{
	list_node::iterator it{ front_ptr };
	list_node::iterator temp{ front_ptr };
	while (it != nullptr)
	{
		temp = it;
		++it;
	}
	return temp;
}

list_node::iterator list::end()
{
	list_node::iterator it(front_ptr);
	while (it != nullptr)
		++it;
	return it;
}