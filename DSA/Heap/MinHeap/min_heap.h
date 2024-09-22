#pragma once
#include <cstdio>

class min_heap
{
private:
    int* heap;
    int size;
    int capacity;
    void swap(int index1, int index2) const;
public:
    min_heap(int* arr, int length, int capacity)
    {
        build_heap(arr, length, capacity);
    }

    void build_heap(int* arr, int length, int capacity);
    void heapify(int index);
    int right_child(int index) const;
    int left_child(int index) const;
    static int parent(int index);
    void pop();
    int peek();
    void insert(int data);
    void print() const;
};


inline void min_heap::build_heap(int* arr, int length, int capacity)
{
    if(length > capacity) length = capacity;
    
    heap = arr;
    size = length;
    this->capacity = capacity;
    for(int i = (length - 1)/2; i>=0;i--)
    {
        heapify(i);
    }
}

inline void min_heap::heapify(int index)
{
    int right_child = index*2+2;
    int left_child = index*2+1;
    int smaller_child = index;
    if(right_child < size && heap[right_child] < heap[smaller_child])
    {
        smaller_child = right_child;
    }
    if(left_child < size && heap[left_child] < heap[smaller_child])
    {
        smaller_child = left_child;
    }

    if(smaller_child != index)
    {
        swap(index, smaller_child);
        heapify(smaller_child);
    }
}

inline void min_heap::swap(int index1, int index2) const
{
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

inline void min_heap::pop()
{
    if(size == 0) return;
    swap(0, size-1);
    size--;
    heapify(0);
}

inline void min_heap::insert(int data)
{
    if(capacity == size) return;
    
    heap[size] = data;
    int index = size;
    size++;
    while(index > 0)
    {
        heapify(parent(index));
        index = parent(index);
    }
}

inline int min_heap::peek()
{
    return heap[0];
}

inline int min_heap::right_child(int index) const
{
    int right_child = index*2 + 2; 
    return right_child >= size ? 0: right_child;    
}

inline int min_heap::left_child(int index) const
{
    int left_child = index*2 + 1; 
    return left_child >= size ? 0: left_child;    
}

inline int min_heap::parent(int index)
{
    return (index-1)/2 > 0 ? (index-1)/2 : 0;
}

inline void min_heap::print() const
{
    for(int i =0;i<size;i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
