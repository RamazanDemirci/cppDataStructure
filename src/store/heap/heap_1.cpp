/*
Heap

Heap data structure is a complete binary tree that satisfied the heap property.
it is also called as a binary heap

A complete binary tree is a special binary tree in which;
    - every level, except possibly the last, is filled
    - all the nodes are as far left as possible
                    1
            4               8
        5       2       3

Heap property is the property of a node in which;
    - (for max heap) key of each node is always greater than its child
                    9
            5               4
        1       3       2
    - (for min heap) key of each node smaller than its child 
                    1
            2               3
        4       5       9

Heap Operations
- Heapify
    - Heapify is the process of creating a heap data structure from binary tree
    1. Let the input array be
        3,9,2,1,4,5
    2. Create a complete binary tree from the array
                    3
            9               2
        1       4       5
    3. Start from the first index of non-leaf node whose index is given n/2-1
    4. Set current element i as largest
    5. The index of left child is given by 2i+1 and the right is given y 2i+2
        if leftChild is greater than currentElement set leftChildIndex as largest
        if rightChild is greater than element in largest set rightChildIndex as 
        largest
    6. Swap largest with currnetElement
                    3
            9               5
        1       4       2
    7. Repeat 3-7 until the subtrees ar also heapified
    - Algorithm
        Heapify(array, size, i)
            set i as largest
            leftChild = 2i+1
            rightChild = 2i+2

            if leftChild &gt; array[largest]
                set leftChildIndex as largest
            if rightChild &gt; array[largest]
                set rightChildIndex as largest
            
            swap array[i] and array[largest]

    - To create Max-Heap
        MaxHeap(array, size)
            loop from the first index of non-leaf node down to zero
            call heapify

Insert Element into Heap
- Algorithm
    InsertElement
        if there is no node
            create a newNode
        else (a node is already present)
            insert the newNode at the end (last node from left to right)
    
    1. Insert new element at the end of the tree
                    9
            4               5
        1       3       2       7
    2. Heapify tree
                    9
            4               7
        1       3       2       5

Delete Element from Heap
- Algorithm
    DeleteElement
        if nodeToBeDeleted is the leafNode
            remove the node
        else swap nodeTobeDeleted with the lastLeafNode
            remove noteToBeDeleted
        heapify the array
    
    1. Select the element to be deleted
                    9
            3               7
        1       4       1       5
    2. Swap it with the last element
                    9
            5               7
        1       4       2       3
    3.Remove the last element
                    9
            5               7
        1       4       2
    4. Heapify the tree
                    9
            5               7
        1       4       2

Peek(Find max/min)
    Peek operation return the maximum(or minimum) element from Max Heap( or Min heap)
    without delete the node

Extract-max/min
    Extract-Max operation return the maximum(or minimum) element after removing it 
    from Max Heap( or Min heap)

Applications:
    Heap is used while implementing a priority queue
    Dijkstra's Algorithm
    Heap Sort
*/

#include <iostream>
#include <vector>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(std::vector<int> &hT, int i)
{
    int size = hT.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] > hT[largest])
        largest = l;
    if (r < size && hT[r] > hT[largest])
        largest = r;
    if (largest != i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}

void insert(std::vector<int> &hT, int newNum)
{
    int size = hT.size();
    if (size == 0)
    {
        hT.push_back(newNum);
    }
    else
    {
        hT.push_back(newNum);
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(hT, i);
        }
    }
}

void deleteNode(std::vector<int> &hT, int num)
{
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == hT[i])
            break;
    }
    swap(&hT[i], &hT[size - 1]);

    hT.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(hT, i);
    }
}

void printArray(std::vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        std::cout << hT[i] << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> heapTree;
    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    std::cout << "Max-Heap array: ";
    printArray(heapTree);
    deleteNode(heapTree, 5);
    std::cout << "After deleting an element: ";
    printArray(heapTree);
    return 0;
}