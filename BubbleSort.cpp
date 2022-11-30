//reccusive implementation of of the "bubble sort" algorith


#include "Header.h"


//side function, returns the lists's length
int len(node* pos)
{
    int counter = 0;
    node* ptr = pos;
    while (ptr != nullptr)
    {
        ptr = ptr->next;
        counter++;
    }
    return counter;
}

//side function, swaps only to first nodes
void swapFirst(node* pos1, node* pos2)
{
    node* first = pos1;
    node* third = pos2->next;
    pos1->next = third;
    pos2->next = first;
}
// side function, swaps two nodes in the middle
void swap(node* before, node* pos1, node* pos2)
{
    node* after = pos2->next;
    pos1->next = after;
    before->next = pos2;
    pos2->next = pos1;


}
//main sort function
node* bubblesort(node* pos)
{
    static int size = len(pos);
    static int run = 0;
    static int times = 0;
    static node* first = pos;
    bool sorted = false;
    if (size == 1)
    {
        return first;
    }
    if (run == 0)
    {
        if (pos->val > pos->next->val)
        {
            first = pos->next;
            node* temp = pos->next;
            swapFirst(pos, pos->next); sorted = true;

        }

    }
    else
    {
        if (pos->next != nullptr)
        {
            if (pos->next->next != nullptr)
            {

                if (pos->next->val > pos->next->next->val)
                {
                    sorted = true;
                    swap(pos, pos->next, pos->next->next);
                }
            }
        }
    }
    run++;

    if (run == size - 1) {
        run = 0;
    }
    if (sorted == false)
    {
        times++;
    }
    else
    {
        times = 0;
    }
    if (times == size - 1)
    {
        return first;
    }
    if (!(run == 0 or run == 1))

    {
        bubblesort(pos->next);
    }
    else {
        bubblesort(first);
    }
}








