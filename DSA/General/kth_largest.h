#pragma once
#include <algorithm>
#include <vector>
#include "../Heap/MinHeap/min_heap.h"

using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/3906260/100-3-approaches-video-heap-quickselect-sorting/
class kth_largest
{
public:
    min_heap *min_heap;    

    kth_largest(vector<int> nums, int k)
    {
        auto *arr = static_cast<int*>(malloc(k*sizeof(int)));
        for(int i =0;i<k;i++)
        {
            arr[i] = nums[i];
        }
        
        min_heap = new class min_heap(arr, k, k);
        min_heap->print();
        for(int i = k;i<nums.size();i++)
        {
            if(nums[i] > min_heap->peek())
            {
                min_heap->pop();
            }
            min_heap->insert(nums[i]);
        }
        min_heap->print();

    }
    
    int add(int val)
    {
        if(val > min_heap->peek())
        {
            min_heap->pop();
        }
        min_heap->insert(val);
        return min_heap->peek();
    }
};
