/*
Letter Combinations of a Phone Number Total Accepted: 5384 Total Submissions: 21289 My Submissions
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

/*
Feb 15 2014
Solution:
DP
We already have letter combination of digits[:i], how to get letter combination of digits [:i+1]?
use the letter combination of digits[:i], append mapping of digits[i] and add to the result.
Reference: http://discuss.leetcode.com/questions/198/letter-combinations-of-a-phone-number
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> rtn;
        string mapping[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        rtn.push_back("");
        int cur;
        int curlen;
        for (int i = 0; i < digits.size(); i++)
        {
            cur = digits[i] - '0';
            curlen = rtn.size();
            for (int k = 0; k < curlen; k++)
            {
                for (int j = mapping[cur].size() - 1; j >= 0; j--)
                {
                    if (j) rtn.push_back(rtn[k]+mapping[cur][j]);
                    else rtn[k] += mapping[cur][j];
                }
            }
        }
        return rtn;
    }
};
