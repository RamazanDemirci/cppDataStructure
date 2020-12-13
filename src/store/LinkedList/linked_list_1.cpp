#include <iostream>

using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void display()
{
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

/*
Singly Linked List

Singly linked list is a type of data structure that is made up of nodes that are 
created using self referential structures

Each of these nodes contain two parts, namely the data and the reference to the next
list node.

the first list node called head

The function insert() inserts the data into the beginning of the linked list

The function display() displays the whole linked list

*/

int main()
{
    std::cout << "Hello Easy C++ project!" << std::endl;
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);
    cout << "The linked list is: ";
    display();
    return 0;
}