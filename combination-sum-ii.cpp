/*
Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

/*
Feb 4 2014
Note:
* "a collection of candidate number" --> there's duplication in the input, need extra work to avoid duplicate outputs --> sort, scan from 0 to n-1, jump over duplication 
* different from combination sum, element is not reuseable

*/

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > rtn;
        if (num.empty()) return rtn;
        vector<int> intermediate;
        sort(num.begin(), num.end());
        addAndSearch(rtn, num, intermediate, 0, target);
        return rtn;
    }

    void addAndSearch(vector<vector<int> > &rtn, vector<int> &num, vector<int> &intermediate, int start, int gap)
    {
        if (!gap)
        {
            rtn.push_back(intermediate);
            return;
        }
        int i = start;
        while(i < num.size())
        {
            if (num[i] > gap) return;
            intermediate.push_back(num[i]);
            addAndSearch(rtn, num, intermediate, i+1, gap-num[i]);
            intermediate.pop_back();
            i++;
            while(num[i-1] == num[i])
            {
                i++;
            }
        }
    }
};


