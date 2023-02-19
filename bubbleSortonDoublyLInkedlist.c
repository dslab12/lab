#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
void insertAtTheBegin(struct Node **start_ref, int data)
{
    struct Node *ptr1 = new Node;
    ptr1->data = data;
    ptr1->next = *start_ref;
    if (*start_ref != NULL)
    (*start_ref)->prev = ptr1;
    *start_ref = ptr1;
}
void display(struct Node *start)
{
    struct Node *temp = start;
    cout << endl;
    while (temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void bubbleSort(struct Node *start)
{
    int swapp, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;
    if (start == NULL)
        return;

    do
    {
        swapp = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1->data, ptr1->next->data);
                swapp = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapp);
}

int main()
{
    int arr[] = {3, 4, 5, 2, 1};
    int list_size, i;
    list_size = sizeof(arr)/sizeof(arr[0]);
    struct Node *start = NULL;
    for (i = 0; i< list_size; i++)
        insertAtTheBegin(&start, arr[i]);
    bubbleSort(start);
    display(start); 
    return 0;
}
</iostream>