#pragma once
#include "Node.h"

class MinHeap
{
    Node* harr;
    int capacity;
    int heap_size;
public:
    void Enqueue(Node newNode);

    std::string Dequeue();

    std::string Peek();

    MinHeap(int capacity);

    void swap(Node* x, Node* y);

    int parent(int i) { return (i - 1) / 2; }

    // для получения индекса левого потомка узла по индексу i
    int left(int i) { return (2 * i + 1); }

    // для получения индекса правого потомка узла по индексу i
    int right(int i) { return (2 * i + 2); }
};