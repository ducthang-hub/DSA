#pragma once
#include "../Node/Node.h"

using namespace std;

class c_queue{
    int size_;
    int front_;
    int rear_;
    Node** q_;  // [Node*]*: Pointer to [Pointer to Node]
public:
    explicit c_queue(int size);
    ~c_queue();
    bool is_full() const;
    bool is_empty() const;
    void enqueue(Node* x);
    Node* dequeue();
};

inline c_queue::c_queue(const int size) {
    this->size_ = size;
    front_ = -1;
    rear_ = -1;
    q_ = new Node* [size];
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

inline void c_queue::enqueue(Node* x) {
    if (is_full()){
        cout << "Queue Overflow" << flush;
    } else {
        rear_++;
        q_[rear_] = x;
    }
}

inline Node* c_queue::dequeue() {
    Node* x = nullptr;
    if (is_empty()){
        cout << "Queue Underflow" << flush;
    } else {
        front_++;
        x = q_[front_];
    }
    return x;
}