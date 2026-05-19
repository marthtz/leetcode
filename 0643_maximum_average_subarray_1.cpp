// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

// Example 1:
// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:
// Input: nums = [5], k = 1
// Output: 5.00000

// Constraints:
//     n == nums.length
//     1 <= k <= n <= 105
//     -104 <= nums[i] <= 104


#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum{0.0};
        double result{0.0};

        auto front_it = nums.begin();
        auto back_it = nums.begin();

        // build sliding window
        for (int i = 0; i < k; ++i)
        {
            sum += *back_it;
            back_it++;
            if (back_it == nums.end())
            {
                return (sum / k);
            }
        }

        result = (sum / k);

        for (; front_it != nums.end(); ++front_it)
        {
            sum -= *front_it;

            if (back_it != nums.end())
            {
                sum += *back_it;
                back_it++;
                auto res = (sum / k);

                if (res > result)
                {
                    result = res;
                }            
            }
            else
            {
                break;
            }
        }         
        return result;
    }
};


