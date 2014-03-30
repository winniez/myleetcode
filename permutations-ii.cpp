/*
Permutations II
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

/*
Mar 23 2014
Solution:
- Similar to permutation, but we need to check if there's a duplicate number swapped with start.
- dp and recursive
- use unordered_set (hashtable) to keep an record of swapped number, avoid doing the swap with number already in set.
Time O(n!) space O(n)
*/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > rtn;
        if (num.empty()) return rtn;
        dp(rtn, num, 0);
        return rtn;
    }

    void dp(vector<vector<int> >& res, vector<int>& num, int start)
    {
        if(start == num.size())
        {
            res.push_back(num);
            return;
        }
        int tmp;
        unordered_set<int> used;
        for(int i = start; i<num.size(); i++)
        {
            if (!used.count(num[i]))
            {
                tmp = num[start];
                num[start] = num[i];
                num[i] = tmp;
                dp(res, num, start+1);
                num[i] = num[start];
                num[start] = tmp;
                used.insert(num[i]);
            }
        }
    }
};
