#pragma once
#include <stack>
#include <unordered_set>

#include "../../Node/Node.h"
#include "../../Queue/c_queue.h"

using namespace std;

class binary_tree
{
private:
    int height_ = 0;
    
    static inline void create_tree(Node* &root);
    static inline void create_tree(int arr[], int length, Node* &root);
    static inline void insert_node(Node* &root, int data);

    bool update_hash_array(vector<int> &vector, int k, int target)
    {
        for(int i =0;i<vector.size();i++)
        {
            if(vector[i] + k == target)
            {
                vector[i] = target;
                return true;
            }
            if(vector[i] == k) return false;
        }
        vector.push_back(k);
        return false;
    }
public:
    Node * root;
    
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

    void inorder_plain(vector<int> &inorder, const Node* node)
    {
        if(!node) return;
                
        inorder_plain(inorder, node->left);
        inorder.push_back(node->val);
        inorder_plain(inorder, node->right);
    }

    void create_tree_by_preorder(int arr[], int length);

    bool find_target(int k)
    {
        if(root == nullptr) return false;

        stack<Node*> stack;
        stack.push(root);
        vector<int> hash_array;
        vector<bool> visitedNode;
        
        while(!stack.empty())
        {
            Node* node = stack.top();
            if(update_hash_array(hash_array, node->val, k)) return true;
            if(node->left != nullptr && node->left->val != INT_MIN)
            {
                stack.push(node->left);
                visitedNode.push_back(node->val);
                continue;
            }
            if(node->right != nullptr && node->right->val != INT_MIN)
            {
                stack.push(node->right);
                visitedNode.push_back(node->val);
                continue;
            }
            node->val = INT_MIN;
            stack.pop();
        }
    }

    
    bool find_target_inorder(Node* root, int k, vector<int> inorder)
    {
        int i=0, j=inorder.size()-1;
        while(i<j)
        {
            if(inorder[i] < k-inorder[j])
            {
                i++;
            }
            else if(inorder[i] > k- inorder[j])
            {
                j--;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
    

    bool find_target_unsorted_set_recursive(Node *root, int k, unordered_set<int> &unordered_set)
    {
        if(!root) return false;
        
        unordered_set.emplace(root->val);
        
        if(unordered_set.find(k-root->val) != unordered_set.end()) return true;

        bool result_left = find_target_unsorted_set_recursive(root->left, k, unordered_set);
        bool result_right = find_target_unsorted_set_recursive(root->right, k, unordered_set);

        return result_left || result_right;
    }

    bool find_target_unsorted_set_loop(Node *root, int k)
    {
        if(!root) return false;

        unordered_set<int> unordered_set;
        stack<Node*> stack;
        stack.push(root);
        
        while(!stack.empty())
        {
            Node* node = stack.top();
            unordered_set.emplace(node->val);

            if(unordered_set.find(k - node->val) != unordered_set.end() && unordered_set.size() != 1) return true;

            if(node->left != nullptr && unordered_set.find(node->left->val) == unordered_set.end())
            {
                stack.push(node->left);
                continue;
            }
            if(node->right != nullptr && unordered_set.find(node->right->val) == unordered_set.end())
            {
                stack.push(node->left);
                continue;
            }
            stack.pop();
        }
        return false;
    }
};

inline void binary_tree::insert_node(Node *&root, const int data)
{
    const auto n = static_cast<Node*>(malloc(sizeof(Node)));
    n->val = data;
    n->left = nullptr;
    n->right = nullptr;
    n->height = 1;
    
    if(root == nullptr)
    {
        root = n;
        return;
    }

    if(data > root->val)
    {
        insert_node(root->right, data);
    }
    else if(data < root->val)
    {
        insert_node(root->left, data);
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

inline void binary_tree::create_tree(Node* &root)
{
    root = new Node;
    Node* t;
    int x;
    c_queue q(10);
 
    cout << "Enter root value: " << flush;
    cin >> x;
    root->val = x;
    root->left = nullptr;
    root->right = nullptr;
    q.enqueue(root);
 
    while (! q.is_empty()){
        Node* p = q.dequeue();
 
        cout << "Enter left child value of " << p->val << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->val = x;
            t->left = nullptr;
            t->right = nullptr;
            p->left = t;
            q.enqueue(t);
        }
 
        cout << "Enter left child value of " << p->val << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->val = x;
            t->left = nullptr;
            t->right = nullptr;
            p->right = t;
            q.enqueue(t);
        }
    }
}

inline void binary_tree::create_tree(int arr[], const int length, Node*& root)
{
    for(int i = 0;i<length; i++)
    {
        insert_node(root, arr[i]);
    }
}

inline void binary_tree::create_tree_by_preorder(int arr[], const int length)
{
    root = static_cast<Node*>(malloc(sizeof(Node)));
    stack<Node*> stk;

    for(int i = 0;i< length; i++)
    {
        if(stk.empty())
        {
            root->left = nullptr;
            root->right = nullptr;
            root->val = arr[i];
            stk.push(root);
        }
        else
        {
            auto top = stk.top();
            if(arr[i] < top->val)
            {
                auto n = static_cast<Node*>(malloc(sizeof(Node)));
                n->left = nullptr;
                n->right = nullptr;
                n->val = arr[i];
                top->left = n;

                stk.push(n);
            }else
            {
                do
                {
                    top = stk.top();
                    stk.pop();
                }
                while(!stk.empty() && arr[i] > stk.top()->val);
                
                auto n = static_cast<Node*>(malloc(sizeof(Node)));
                n->left = nullptr;
                n->right = nullptr;
                n->val = arr[i];
                
                top->right = n;
                stk.push(n);
            }
        }
    }
}


