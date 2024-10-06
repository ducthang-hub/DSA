#pragma once
#include <stack>
#include <vector>
#include "../../Node/Node.h"

using namespace std;

class leet_code
{
public:
    static int find_only_missing_number(vector<int>& nums)
    {
        auto length = nums.size();
        auto sum_nums = length*(length+1)/2;
        auto sum = 0;
        
        for(int i = 0; i<length; i++)
        {
            sum+=nums[i];
        }

        return sum_nums - sum;
    }

    static bool find_target(Node* root, int k)
    {
        if(root == nullptr) return false;

        stack<Node*> stack;
        stack.push(root);
        vector<int> hash_array;
        vector<bool> visitedNode;
        
        while(!stack.empty())
        {
            Node* node = stack.top();
            update_hash_array(hash_array, node->val, k);
            if(node->left != nullptr)
            {
                stack.push(node->left);
                visitedNode.push_back(node->val);
                continue;
            }
            if(node->right != nullptr)
            {
                stack.push(node->right);
                visitedNode.push_back(node->val);
                continue;
            }
            node = nullptr;
            stack.pop();
        }
    }

    static void update_hash_array(vector<int> &vector, int k, int target)
    {
        for(int i =0;i<vector.size();i++)
        {
            if(vector[i] + k == target)
            {
                vector[i] = target;
                return;
            }
        }
        vector.push_back(k);
    }
};
