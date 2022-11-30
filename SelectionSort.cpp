//recursive implementation of selection sort algorithm for linked list

#include "Header.h"

node* selection_sort(node* pos) {
	if (pos->next == nullptr) {
		return pos;
	}
	node* ptr;
	node* before_min = nullptr;
	node* min = pos;
	for (ptr = pos; ptr->next != nullptr; ptr = ptr->next) {
		if (ptr->next->val < min->val) {
			min = ptr->next;
			before_min = ptr;
		}
	}
	if (min != pos) {
		pos = bringToFront(pos, before_min, min);
	}
	pos->next = selection_sort(pos->next);
	return pos;
}

//bring node to front of linked list - side function for selection sort
node* bringToFront(node* current, node* before, node* min)
{
	before->next = min->next;
	min->next = current;
	return min;
}