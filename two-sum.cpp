/*
Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/*
JAN 19 2014

The n^2 solution is too slow
Use hash map.
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> rtn;
        if (numbers.empty()) return rtn;
        int tmp;
        map<int, vector<int> >table;
        for (int i = 0; i < numbers.size(); i++)
        {
            tmp = numbers[i];
            if (!table.count(tmp))
            {
                vector<int> indices;
                table[tmp] = indices;
            }
            table[tmp].push_back(i);
        }
        for (int i = 0; i < numbers.size(); i++)
        {
            tmp = target-numbers[i];
            if (table.count(tmp))
            {
                for (int j = 0; j < table[tmp].size(); j++)
                {
                    if (table[tmp][j] != i)
                    {
                        if (table[tmp][j]<i)
                        {
                            rtn.push_back(table[tmp][j]+1);
                            rtn.push_back(i+1);
                        }
                        else
                        {
                            rtn.push_back(i+1);
                            rtn.push_back(table[tmp][j]+1);
                        }
                        return rtn;
                    }
                }
            }
        }
        return rtn;
    }
};
