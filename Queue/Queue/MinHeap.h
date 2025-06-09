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

    // ��� ��������� ������� ������ ������� ���� �� ������� i
    int left(int i) { return (2 * i + 1); }

    // ��� ��������� ������� ������� ������� ���� �� ������� i
    int right(int i) { return (2 * i + 2); }
};