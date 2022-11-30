//my recursive implementation of linked list sorting
#include "Header.h"



//side function , handles the last node
node* insertAndRemove(node* chain, node* pos)
{
    node* ptr = chain;
    if (chain == ptr)
    {
        return ptr;
    }
    while (ptr->next->next != nullptr)
    {
        ptr = ptr->next;
    }
    if (ptr->val < pos->val)
    {
        return chain;
    }
    ptr->next = nullptr;
    if (pos->val < chain->val)
    {
        pos->next = chain;
        return pos;
    }
    for (node* p = chain; p->next->next != nullptr; p = p->next)
    {
        if (ptr->next->val > pos->val) {
            node* after = ptr->next;
            ptr->next = pos;
            pos->next = after;
            return chain;
        }
    }
}
//bring biggest node to front, side function
void swap(node* first, node* before, node* pos)
{
    before->next = before->next->next;
    pos->next = first;
}
//main sort function
node* weirdSort(node* pos)
{
    static node* first = pos;
    if (pos == nullptr or pos->next == nullptr)
    {

        return insertAndRemove(first, pos);
    }
    int biggest = pos->next->val;
    node* ptr = pos;
    node* before = pos;
    while (ptr->next != nullptr)
    {
        if (ptr->next->val > biggest)
        {
            biggest = ptr->next->val;
            before = ptr;
        }
        ptr = ptr->next;
    }
    node* firsthold = before->next;
    swap(first, before, before->next);
    first = firsthold;
    weirdSort(pos);

}
