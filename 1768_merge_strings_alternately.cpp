#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {


    auto total_length = word1.length() + word2.length();

    string merged_string;
    merged_string.reserve(total_length); // Reserve space for the merged string

    string::iterator word1_it = word1.begin();
    string::iterator word2_it = word2.begin();

    for (auto total_length = 0; total_length < word1.length() + word2.length(); total_length++)
    {
        if (word1_it != word1.end())
        {
            merged_string.push_back(*word1_it);
            word1_it++;
        }
        
        if (word2_it != word2.end())
        {
            merged_string.push_back(*word2_it);
            word2_it++;
        }
    }

    return merged_string;
    }
};


int main()
{
    Solution solution;
    string word1 = "abc";
    string word2 = "pqr";
    string merged_string = solution.mergeAlternately(word1, word2);
    cout << "Merged String: " << merged_string << endl;

    return 0;
}