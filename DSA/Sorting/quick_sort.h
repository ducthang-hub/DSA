#pragma once
#include <queue>
#include <vector>

using namespace std;

class quick_sort
{
public:
    static void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void static sort(int *arr, int length)
    {
        int left = 0;
        int right = length -1;
        partition(arr, left, right);
    }

    void static partition(int *arr, int left, int right)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pg;
        if(left >= right) return;
        int pivot_index = (left + right)/2;
        int pivot_value = arr[pivot_index];

        swap(arr[pivot_index], arr[right]);

        int ready_to_swap_index = left;
        for(int i = left; i<right;i++)
        {
            if(pivot_value > arr[i])
            {
                swap(arr[ready_to_swap_index], arr[i]);
                ready_to_swap_index++;
            }
        }

        swap(arr[right], arr[ready_to_swap_index]);

        partition(arr, ready_to_swap_index+1, right);
        partition(arr, left, ready_to_swap_index-1);
    }
    
    int static select_kth_largest(int *arr, int length, int k)
    {
        std::vector<int> i;
        if(k >= length) return 0;
        int left = 0;
        int right = length - 1;
        while(true)
        {
            int stored_index = kth_largest_item(arr, left, right);
            if(stored_index == k-1) return arr[stored_index];
            if(stored_index < k-1)
            {
                left = stored_index+1;
            }
            else if(stored_index > k-1)
            {
                right = stored_index-1;
            }
        }
    }

    int static kth_largest_item(int *arr, int left, int right)
    {
        int pivot_index = (left + right)/2;
        int pivot = arr[pivot_index];
        
        int stored_index = left;
        swap(arr[pivot_index], arr[right]);
        
        for(int i = left; i<right;i++)
        {
            if(pivot < arr[i])
            {
                swap(arr[i], arr[stored_index]);
                stored_index++;
            }
        }
        swap(arr[right], arr[stored_index]);
        return stored_index;
    }
};
