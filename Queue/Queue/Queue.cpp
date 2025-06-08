// Variant 2
#include <iostream>
#include <climits>
using namespace std;

// Прототип функции-утилиты для обмена двух целых чисел
void swap(int* x, int* y);

// Класс для Min Heap
class MinHeap
{
    int* harr;     // указатель на массив элементов в куче
    int capacity;  // максимально возможный размер минимальной кучи
    int heap_size; // Текущее количество элементов в минимальной куче
public:
    // Конструктор
    MinHeap(int capacity);

    // для создания кучи поддерева с корнем по заданному индексу
    void MinHeapify(int i);

    int parent(int i) { return (i - 1) / 2; }

    // для получения индекса левого потомка узла по индексу i
    int left(int i) { return (2 * i + 1); }

    // для получения индекса правого потомка узла по индексу i
    int right(int i) { return (2 * i + 2); }

    // для извлечения корня, который является минимальным элементом
    int extractMin();

    // Уменьшает значение ключа по индексу i до new_val
    void decreaseKey(int i, int new_val);

    // Возвращает минимальный ключ (ключ в корне) из минимальной кучи
    int getMin() { return harr[0]; }

    // Удаляет ключ, сохраненный по индексу i
    void deleteKey(int i);

    // Вставляет новый ключ 'k'
    void insertKey(int k);
};

// Конструктор: создает кучу из заданного массива a[] заданного размера
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Вставляет новый ключ 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // Сначала вставляем новый ключ в конец
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Исправляем свойство min heap, если оно нарушено
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Уменьшает значение ключа с индексом 'i' до new_val. Предполагается, что
// new_val меньше harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Метод удаления минимального элемента (или корня) из кучи min
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // Сохранение минимального значения и удаление его из кучи
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}

// Эта функция удаляет ключ по индексу i. Сначала она уменьшает значение до минус
// бесконечности, затем вызывает extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// Рекурсивный метод для кучи поддерева с корнем по заданному индексу
// Этот метод предполагает, что поддеревья уже кучированы
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// Вспомогательная функция для обмена двух элементов
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Программа-драйвер для проверки вышеуказанных функций
int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}