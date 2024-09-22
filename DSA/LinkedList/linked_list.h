#pragma once
#include <stdio.h>
#include "../Node/node.h"

using namespace std;

class linked_list
{
public:
    node* head;
    void reverse_by_sliding_pointer();
    void print_linked_list();
    
    explicit linked_list(const int data)
    {
        head = static_cast<node*>(malloc(sizeof(node)));
        head->data = data;
        head->next = nullptr;
    }

    
    explicit linked_list(const int data[], int length)
    {
        head = static_cast<node*>(malloc(sizeof(node)));
        head->data = data[0];
        auto iterate = head;
        
        for(int i = 1;i<length; i++)
        {
            auto n = static_cast<node*>(malloc(sizeof(node)));
            n->data = data[i];
            n->next = nullptr;
            iterate->next = n;
            iterate = iterate->next;
        }
    }

    
    ~linked_list()
    {
        const node* iterate = head;
        while(iterate != nullptr)
        {
            const node* temp = iterate->next;
            delete iterate;
            iterate = temp;
        }
    }
};

inline void linked_list::reverse_by_sliding_pointer()
{
    node* previous = nullptr;
    node* current = head;
    node* next = head->next;

    while(current != nullptr)
    {
        head = current;
        current->next = previous;
        previous = current;
        current = next;
        next = next != nullptr ? next->next : nullptr;
    }
}

inline void linked_list::print_linked_list()
{
    while(head!= nullptr)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}


