#pragma once
#include <stdio.h>
#include "../Node/Node.h"

using namespace std;

class linked_list
{
public:
    Node* head;
    void reverse_by_sliding_pointer();
    void print_linked_list();
    
    explicit linked_list(const int data)
    {
        head = static_cast<Node*>(malloc(sizeof(Node)));
        head->val = data;
        head->next = nullptr;
    }

    
    explicit linked_list(const int data[], int length)
    {
        head = static_cast<Node*>(malloc(sizeof(Node)));
        head->val = data[0];
        auto iterate = head;
        
        for(int i = 1;i<length; i++)
        {
            auto n = static_cast<Node*>(malloc(sizeof(Node)));
            n->val = data[i];
            n->next = nullptr;
            iterate->next = n;
            iterate = iterate->next;
        }
    }
    
    ~linked_list()
    {
        const Node* iterate = head;
        while(iterate != nullptr)
        {
            const Node* temp = iterate->next;
            delete iterate;
            iterate = temp;
        }
    }
};

inline void linked_list::reverse_by_sliding_pointer()
{
    Node* previous = nullptr;
    Node* current = head;
    Node* next = head->next;

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
        printf("%d ", head->val);
        head = head->next;
    }
}


