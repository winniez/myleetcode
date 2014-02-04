/*
Combination Sum
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/

/*
JAN 27 2014
Solution:
dfs and recursion

Because the problem is to get all the possible results, not the best or the number of result, thus we don't need to consider DP(dynamic programming), DFS is enough to handle it.

The idea is to scan from the first to the last element from the ordered array. check every possible combination of these numbers(multiple times for a single element).

the end condition of the dfs function is
1. the target ==0 , print list, return
2. the target < 0 return
3. start position >= array size return
otherwise, from for each element in the array, dfs(start, target-element value);

Note:
* "a set of candidate" --> no duplication in candidates
* element is useable --> pass in i instead of i+1 when recursively calling addAndSearch
Reference:
combination-sum
http://discuss.leetcode.com/questions/61/combination-sum

*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > rtn;
        if (candidates.empty()) return rtn;
        sort(candidates.begin(), candidates.end());
        vector<int> intermediate;
        addAndSearch(candidates, rtn, intermediate, 0, target);
        return rtn;
    }
// solve the problem recursively
    void addAndSearch(vector<int> &candidates, vector<vector<int> > &rtn, vector<int> &intermediate, int start, int gap)
    {
        if (!gap)
        {
            rtn.push_back(intermediate);
            return;
        }
        for (int i = start; i<candidates.size(); i++)
        {
            if (gap < candidates[i]) return; //prune
            intermediate.push_back(candidates[i]); //extend
            // element is useable, pass in i
            addAndSearch(candidates, rtn, intermediate, i, gap-candidates[i]);
            intermediate.pop_back(); // jump over the element
        }
    }
};
