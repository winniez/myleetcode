/*
Permutations
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
/*
Mar 23 2014
solution:
recursively solve s[0~n-1], s[1~n-1],...,s[n-2~n-1] subarray and use the result.
s[0~n-1] results on built on top of s[1~n-1].

Reference:
http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
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
        for(int i = start; i<num.size(); i++)
        {
            // swap first elemet with any element in the subarray
            tmp = num[start];
            num[start] = num[i];
            num[i] = tmp;
            // permutate smaller subarray
            dp(res, num, start+1);
            // restore given array
            num[i] = num[start];
            num[start] = tmp;
        }
    }
};

