/*
HashTable

HashTable is a data structure that represents data in the form of key-value pairs.
Each key is mapped to a value in the hash table.
The keys are used for indexing the values/data.
A similar approach is applied by an associative array.

1. Direct Address TAble
Direct address table is used when the amount of space used by the table is not a 
problem for the program.Here, we assume that
- the keys are small integers
- the number of keys is not too large
- no two data have the same key

A pool of integers is taken called universe U = {0,1,...,n-1}
Each slot of a direct address table T[0...n-1] contains a pointer to the element 
that corresponds to the data

The index of a array T is the key itself and the content of T is a pointer to the 
set [key, element]. If there is no element for a key then, it is left as NULL

Limitation of a Direct Address Table
- The value of the key should be small
- The number of keys must be small enough so that it does not cross the size limit 
of an array

Pseudocode for Operations:
    directAddressSearch(T, k)
        return T[k]
    directAddressInsert(T, x)
        T[x.key] = x
    directAddressDelete(T, x)
        T[x.key] = NULL

Hash Table:
In a hash table, the keys are processed to produce a new index that maps to the 
required element. This process is called hashing.

Let h(x) be a hash dunction and k be a key.
h(k) is calculated and it is used as an index for the element.

Limitations of a Hash Table:
- If the same index is produced by tha hash function for multiple keys then,
then conflict arises. This situation is called collision
    To avoid this, a suitable hash function is chosen. But, it is impossible to
    produce all unique keys because |U|>m. Thus a good hash functionmay not prevent 
    the collisions completely however it can reduce the number of collisions
However, we have other techniques to resolve collision.

Advantages of Hash Table over direct address table:
- The main issues with direct address table are the size of the array and the 
possibly large value of a key
- The hash function reduces the range of index and thus the size of the array 
is also reduced
 // For example, If k = 9845648451321, then h(k) = 11 (by using some hash function). 
    This helps in saving the memory wasted while providing the index of 
    9845648451321 to the array

Collision resolution by chaining:
- In this technique, if a hash function produces the same index for multiple 
elements, these elements are stored in the same index by using a doubly linked list.
- If j is the slot for multiple elements, it contains a pointer to the head of the 
list of elements. If no element is present, j contains NIL.

Pseudocode for operations:
    chainedHashSearch(T, k)
        return T[h(k)]
    chainedHashInsert(T, x)
        T[h(x.key)] = x //insert at the head
    chainedHashDelete(T, x)
        T[h(x.key)] = NIL

refs: https://www.programiz.com/dsa/hash-table

*/

// Implementing hash table in C++

#include <iostream>
#include <list>

class HashTable
{
    int capacity;
    std::list<int> *table;

public:
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);

    int checkPrime(int n)
    {
        int i;
        if (n == 1 || n == 0)
        {
            return 0;
        }
        for (i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    int getPrime(int n)
    {
        if (n % 2 == 0)
        {
            n++;
        }
        while (!checkPrime(n))
        {
            n += 2;
        }
        return n;
    }

    int hashFunction(int key)
    {
        return (key % capacity);
    }
    void displayHash();
};
HashTable::HashTable(int c)
{
    int size = getPrime(c);
    this->capacity = size;
    table = new std::list<int>[capacity];
}
void HashTable::insertItem(int key, int data)
{
    int index = hashFunction(key);
    table[index].push_back(data);
}

void HashTable::deleteItem(int key)
{
    int index = hashFunction(key);

    std::list<int>::iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void HashTable::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        std::cout << "table[" << i << "]";
        for (auto x : table[i])
            std::cout << " --> " << x;
        std::cout << std::endl;
    }
}

int main()
{
    int key[] = {231, 321, 212, 321, 433, 262};
    int data[] = {123, 432, 523, 43, 423, 111};
    int size = sizeof(key) / sizeof(key[0]);

    HashTable h(size);

    int n = sizeof(key) / sizeof(int);

    for (int i = 0; i < n; i++)
        h.insertItem(key[i], data[i]);

    h.deleteItem(12);
    h.displayHash();
}