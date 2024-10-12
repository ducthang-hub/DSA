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

    static bool validPalindrome(string s) {
        if(s.length() == 0) return true;

        int i =0;
        int j = s.length()-1;
        int count = 0;
        
        while(i<j){
            if(s[i] == s[j]) {
                // printf("%c - %c\n", s[i], s[j]);
                i++;
                j--;
            }
            else {
                printf("%d.%c - %d.%c\n", i, s[i], j, s[j]);
                if(s[i+1] == s[j]){
                // printf("%d.%c - %d.%c\n", i, s[i], j, s[j]);
                    i++;
                    count++;
                }
                else if (s[i]==s[j-1]){
                    // printf("%c - %c\n", s[i], s[j-1]);
                    j--;
                    count++;
                }
                else{
                    // printf("%c - %c\n", s[i], s[j-1]);
                    j--;
                    count++;
                }
            }
        }
        
        if(count < 2) return true;

        return false;
    }

    void sortColors(vector<int>& nums) {
        int size = nums.size();
        for(int i =0;i<size;i++){
            for(int j =0;j<size-i-1;j++){
                if(nums[j]<nums[j+1]){
                    int temp = nums[j];
                    nums[j]= nums[j+1];
                    nums[j+1]= nums[j];
                }
            }
        }
    }

    Node* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        auto root = static_cast<Node*>(malloc(sizeof(Node)));
        root->val = preorder[0];

        for(int i = 1;i<preorder.size();i++)
        {
            
        }
    }
};
