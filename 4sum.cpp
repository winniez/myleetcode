/*
4Sum
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

/*
JAN 20 2014
Analysis:
Resembles the 3 sum problem.
The Key point in this problem is to iterate through the list, completely and avoid duplication.
- Fix first 2 index with loop;
- Search among the subarray for the last 2;
-- 3rd index start from the start of subarray, 4th index start from the end of subarray

- to avoid duplication, use a hashmap here to store the result already and to return vector. The key of map is string.

Reference:
http://jane4532.blogspot.com/2013/06/4sumleetcode.html
Time complexity: O(n^3)
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > rtn;
        if (num.size()<4) return rtn;
        sort(num.begin(), num.end());
        vector<int> candidate(4,0);
        map<string, int> sets;
        int a, b, c, d, sum2, sum3, sum4, ia, ib, ic, id;
        string tmp;
        for (int i = 0; i<num.size()-3; i++)
        {
            if ( i > 0 && num[i-1] == num[i]) continue;
            for (int j = i+1; j<num.size()-2; j++)
            {
                if (j > i+1 && num[j-1]==num[j]) continue;
                sum2 = num[i]+num[j];
                ic = j+1;
                id = num.size()-1;
                while(ic<id)
                {
                    sum4 = sum2+num[ic]+num[id];
                    if ( sum4 == target)
                    {
                        tmp.clear();
                        tmp += to_string(num[i]);
                        tmp += to_string(num[j]);
                        tmp += to_string(num[ic]);
                        tmp += to_string(num[id]);
                        if (!sets.count(tmp))
                        {
                            sets[tmp] = 1;
                            candidate[0] = num[i];
                            candidate[1] = num[j];
                            candidate[2] = num[ic];
                            candidate[3] = num[id];
                            rtn.push_back(candidate);
                        }
                        ic++;
                        id--;
                    }
                    if ( sum4 < target)
                    {
                        ic++;
                    }
                    if (sum4 > target)
                    {
                        id--;
                    }
                }
            }
        }
        return rtn;
    }
};
