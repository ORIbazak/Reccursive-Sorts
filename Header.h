#pragma once
class node
{
public:
	node* next;
	int val;
};

//my sort headers
node* insertAndRemove(node* chain, node* pos);

void swap(node* first, node* before, node* pos);

node* weirdSort(node* pos);


//bubble sort headers

int len(node* pos);

void swapFirst(node* pos1, node* pos2);

void swap(node* before, node* pos1, node* pos2);

node* bubblesort(node* pos);


//selction sort headers

node* selection_sort(node* pos);

node* bringToFront(node* current, node* before, node* min);


