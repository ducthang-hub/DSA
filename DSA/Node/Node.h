#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class Node
{
private:
    static void print_bt(const std::string& prefix, const Node* node, const bool is_left)
    {
        SetConsoleOutputCP(CP_UTF8);
        std::ios::sync_with_stdio(false); 
        if( node != nullptr )
        {
            std::cout << prefix;
            
            std::cout << prefix;

            std::cout << (is_left ? "├──" : "└──" );

            // print the value of the node
            std::cout << node->val << std::endl;

            // enter the next tree level - left and right branch
            print_bt( prefix + (is_left ? "│   " : "    "), node->left, true);
            print_bt( prefix + (is_left ? "│   " : "    "), node->right, false);
        }
    }
public:
    Node* left;
    Node* right;
    Node* next;
    int val;
    int height;

    void print_bt() const
    {
        print_bt("", this, false);    
    }
};

