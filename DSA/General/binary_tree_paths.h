#pragma once
#include <stack>
#include <string>
#include <vector>
#include "../Node/Node.h"

class binary_tree_paths
{
private:
    static void binaryTreePathsRecursive(Node* root, string path, vector<string> &result);
public:
    static vector<string> binaryTreePaths(Node* root);
    static vector<string> binaryTreePathsRecursive(Node* root);
};

//https://leetcode.com/problems/binary-tree-paths/description/
inline vector<string> binary_tree_paths::binaryTreePaths(Node* root)
{
    if(root == nullptr) return {};

    vector<string> result;
    stack<pair<Node*, string>> s;
    
    s.emplace(root, "");

    while(!s.empty())
    {
        pair<Node*, string> node = s.top();
        s.pop();

        if(node.first->left == nullptr && node.first->right == nullptr)
        {
            result.push_back(node.second + to_string(node.first->val));
        }
        if(node.first->right != nullptr)
        {
            s.emplace(node.first->right, node.second + to_string(node.first->val) + "->");
        }
        if(node.first->left != nullptr)
        {
            s.emplace(node.first->left, node.second + to_string(node.first->val) + "->");
        }
    }

    return result;
}

inline vector<string> binary_tree_paths::binaryTreePathsRecursive(Node* root)
{
    vector<string> result;
    binaryTreePathsRecursive(root, "", result);
    return result;
}


inline vector<string> binary_tree_paths::binaryTreePathsRecursive(Node* root, string path, vector<string> result)
{
    if(root->left == nullptr || root->right == nullptr)
    {
        result.push_back(path + root->val);
    }
    else
    {
        if(root->left != nullptr)
        {
            binaryTreePathsRecursive(root->left, path+root->val, result);
        }
        if(root->right != nullptr)
        {
            binaryTreePathsRecursive(root->right, path+root->val, result);
        }
    }
}


