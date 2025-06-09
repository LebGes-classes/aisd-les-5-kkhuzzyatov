// Variant 2
#include "MinHeap.h"
#include <iostream>
#include <climits>
using namespace std;

void MinHeap::Enqueue(Node newNode)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while (i != 0 && harr[parent(i)].getPriority() > harr[i].getPriority())
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

std::string MinHeap::Dequeue();
{
    if (heap_size <= 0)
        return "";
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0].getValue();
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root.getValue();
}

std::string MinHeap::Peek();
{
    if (heap_size <= 0)
        return "";
    if (heap_size == 1)
    {
        return harr[0].getValue();
    }

    Node root = harr[0];
    harr[0] = harr[heap_size - 1];
    MinHeapify(0);

    return root.getValue();
}

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new Node[cap];
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].getPriority() < harr[i].getPriority())
        smallest = l;
    if (r < heap_size && harr[r].getPriority() < harr[smallest].getPriority())
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(Node* x, Node* y)
{
    Node temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    MinHeap h(5);
    h.Enqueue(Node (1, "1"));
    h.Enqueue(Node(2, "2"));
    cout << h.Peek() << " ";
    h.Enqueue(Node (15, "15"));
    h.Enqueue(Node (5, "5"));
    h.Enqueue(Node (4, "4"));
    cout << h.Peek() << " ";
    cout << h.Dequeue() << " ";
    cout << h.Dequeue() << " ";
    cout << h.Dequeue() << " ";
    h.Enqueue(Node (45, "45"));
    return 0;
}