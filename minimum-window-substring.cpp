/*
Minimum Window Substring
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
/*
Mar 3 2014
Solution:
Use a greedy algorithm with a head pointer and a tail pointer. First move forward tail pointer to find a substring of S containing every character of T. Then move forward head pointer to reduce the length of this substring as low as possible.

The tricky part is that how do we know a substring of S contains every character of T. We use an array toFind to count the number of each different character of T at first. Then we dynamically maintain an array hasFound to count the number of each different character of substring currently. In case every element currentAlphaStat is equal or larger than TAlphaStat, we know that the substring contains all the characters.
Reference:
http://leetcode.com/2010/11/finding-minimum-window-in-s-which.html
*/
class Solution {
public:
    string minWindow(string S, string T) {
        if (T == "") return "";
        int toFind[256] = {0};
        int hasFound[256] = {0};
        int cnt = 0, start = 0, end = 0, minwindow = INT_MAX;
        int minstart, minend;
        for (int i = 0; i < T.size(); i++) toFind[T[i]]++;
        for (start = 0, end = 0; end < S.size(); end++)
        {
            if (toFind[S[end]])
            {
                hasFound[S[end]]++;
                if (hasFound[S[end]] <= toFind[S[end]]) cnt++;

                if (cnt == T.size())
                {
                    while(toFind[S[start]] == 0 || toFind[S[start]] < hasFound[S[start]])
                    {
                        if (toFind[S[start]] < hasFound[S[start]]) hasFound[S[start]]--;
                        start++;
                    }
                    if (end-start+1 < minwindow)
                    {
                        minwindow = end-start+1;
                        minstart = start;
                        minend = end;
                    }
                }
            }
        }
        if (cnt != T.size()) return "";
        return string(S, minstart, minwindow);
    }
};

