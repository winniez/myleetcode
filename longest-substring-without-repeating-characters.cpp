/*
Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
/*
Feb 17 2014
Solution:
Time O(n), space O(1).
Use a vector to keep track of latest indices of character's appearance.
When you have found a repeated character (let’s say at index j), it means that the current substring (excluding the repeated character of course) is a potential maximum, so update the maximum if necessary. It also means that the repeated character must have appeared before at an index i, where i is less than j.

Since you know that all substrings that start before or at index i would be less than your current maximum, you can safely start to look for the next substring with head which starts exactly at index i+1.

Therefore, you would need two indices to record the head and the tail of the current substring. Since i and j both traverse at most n steps, the worst case would be 2n steps, which the run time complexity must be O(n).

Reference:
http://discuss.leetcode.com/questions/154/longest-substring-without-repeating-characters/1166
http://leetcode.com/2011/05/longest-substring-without-repeating-characters.html
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        vector<int> appear(256, -1);
        int maxlen = INT_MIN, start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            start = max(start, appear[s[i]] + 1);
            appear[s[i]] = i;
            maxlen = max(maxlen, i-start+1);
        }
        return maxlen;
    }
};
