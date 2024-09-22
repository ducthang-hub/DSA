#pragma once
#include <vector>

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
};
