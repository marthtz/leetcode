// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.

// Example 1:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Example 2:
// Input: nums = [0]
// Output: [0]

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        auto it = nums.begin();

        for (auto num : nums)
        {
            if (num != 0)    
            {
                *it = num;
                it++;
            }
        }

        for (; it != nums.end(); it++)
        {
            *it = 0;
        }        
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 0, 3, 12};

    s.moveZeroes(nums);

    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}