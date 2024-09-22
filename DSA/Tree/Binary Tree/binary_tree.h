#pragma once
#include <stack>

#include "../../Node/node.h"
#include "../../Queue/c_queue.h"

class binary_tree
{
private:
    int height_ = 0;
    
    static inline void create_tree(node* &root);
    static inline void create_tree(int arr[], int length, node* &root);
    static inline void insert_node(node* &root, int data);
public:
    node * root;
    
    void create_tree()
    {
        create_tree(root);
    }

    void create_tree(int arr[], const int length)
    {
        create_tree(arr, length, root);
    }

    void insert_node(const int data)
    {
        insert_node(root, data);
    }

    void create_tree_by_preorder(int arr[], int length);
};

inline void binary_tree::insert_node(node *&root, const int data)
{
    const auto n = static_cast<node*>(malloc(sizeof(node)));
    n->data = data;
    n->lchild = nullptr;
    n->rchild = nullptr;
    n->height = 1;
    
    if(root == nullptr)
    {
        root = n;
        return;
    }

    if(data > root->data)
    {
        insert_node(root->rchild, data);
    }
    else if(data < root->data)
    {
        insert_node(root->lchild, data);
    }
    
    // if(BalanceFactor(rootx) == 2)
    // {
    //     if(BalanceFactor(rootx->lchild) == 1)
    //         LLRotation(rootx);
    //     else if(BalanceFactor(rootx->lchild) == -1)
    //         LRRotation(rootx);
    // }
    //
    // if(BalanceFactor(rootx) == -2)
    // {
    //     if(BalanceFactor(rootx->rchild) == -1)
    //         RRRotation(rootx);
    //     else if(BalanceFactor(rootx->rchild) == 1)
    //         RLRotation(rootx);
    // }
}

inline void binary_tree::create_tree(node* &root)
{
    root = new node;
    node* t;
    int x;
    c_queue q(10);
 
    cout << "Enter root value: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);
 
    while (! q.is_empty()){
        node* p = q.dequeue();
 
        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
 
        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

inline void binary_tree::create_tree(int arr[], const int length, node*& root)
{
    for(int i = 0;i<length; i++)
    {
        insert_node(root, arr[i]);
    }
}

inline void binary_tree::create_tree_by_preorder(int arr[], const int length)
{
    root = static_cast<node*>(malloc(sizeof(node)));
    stack<node*> stk;

    for(int i = 0;i< length; i++)
    {
        if(stk.empty())
        {
            root->lchild = nullptr;
            root->rchild = nullptr;
            root->data = arr[i];
            stk.push(root);
        }
        else
        {
            auto top = stk.top();
            if(arr[i] < top->data)
            {
                auto n = static_cast<node*>(malloc(sizeof(node)));
                n->lchild = nullptr;
                n->rchild = nullptr;
                n->data = arr[i];
                top->lchild = n;

                stk.push(n);
            }else
            {
                do
                {
                    top = stk.top();
                    stk.pop();
                }
                while(!stk.empty() && arr[i] > stk.top()->data);
                
                auto n = static_cast<node*>(malloc(sizeof(node)));
                n->lchild = nullptr;
                n->rchild = nullptr;
                n->data = arr[i];
                
                top->rchild = n;
                stk.push(n);
            }
        }
    }
}


