#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class node
{
private:
    static void print_bt(const std::string& prefix, const node* node, const bool is_left)
    {
        SetConsoleOutputCP(CP_UTF8);
        std::ios::sync_with_stdio(false); 
        if( node != nullptr )
        {
            std::cout << prefix;
            
            std::cout << prefix;

            std::cout << (is_left ? "├──" : "└──" );

            // print the value of the node
            std::cout << node->data << std::endl;

            // enter the next tree level - left and right branch
            print_bt( prefix + (is_left ? "│   " : "    "), node->lchild, true);
            print_bt( prefix + (is_left ? "│   " : "    "), node->rchild, false);
        }
    }
public:
    node* lchild;
    node* rchild;
    node* next;
    int data;
    int height;

    void print_bt() const
    {
        print_bt("", this, false);    
    }
};

