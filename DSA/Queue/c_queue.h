#pragma once
#include "../Node/node.h"

using namespace std;

class c_queue{
    int size_;
    int front_;
    int rear_;
    node** q_;  // [Node*]*: Pointer to [Pointer to Node]
public:
    explicit c_queue(int size);
    ~c_queue();
    bool is_full() const;
    bool is_empty() const;
    void enqueue(node* x);
    node* dequeue();
};

inline c_queue::c_queue(const int size) {
    this->size_ = size;
    front_ = -1;
    rear_ = -1;
    q_ = new node* [size];
}

inline c_queue::~c_queue() {
    delete [] q_;
}

inline bool c_queue::is_empty() const
{
    if (front_ == rear_){
        return true;
    }
    return false;
}

inline bool c_queue::is_full() const
{
    if (rear_ == size_-1){
        return true;
    }
    return false;
}

inline void c_queue::enqueue(node* x) {
    if (is_full()){
        cout << "Queue Overflow" << flush;
    } else {
        rear_++;
        q_[rear_] = x;
    }
}

inline node* c_queue::dequeue() {
    node* x = nullptr;
    if (is_empty()){
        cout << "Queue Underflow" << flush;
    } else {
        front_++;
        x = q_[front_];
    }
    return x;
}