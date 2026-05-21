// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]

// Constraints:
//     1 <= temperatures.length <= 105
//     30 <= temperatures[i] <= 100
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> result;
        result.reserve(temperatures.size());

        // brute force - exceeds time limit but works on TC1-3
        for (auto it1 = temperatures.begin(); it1 != temperatures.end(); it1++)
        {
            auto temp_it{it1 + 1};

            int idx{0};
            bool ever_hotter{false};
            for (; temp_it != temperatures.end(); temp_it++)
            {
                idx++;
                if (*temp_it > *it1)
                {
                    ever_hotter = true;
                    break;
                }
            }
            if (ever_hotter)
            {
                result.push_back(idx);
            }
            else
            {
                result.push_back(0);
            }
        }
        return result;
    }
};