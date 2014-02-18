/*
Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
/*
Feb 17 2014
Solution:
use a stack to maintain indices of left parenthesis.
Reference:
http://jane4532.blogspot.com/2013/07/longest-valid-parenthesisleetcode.html
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        stack<int> st;
        int curlen = 0, maxlen = 0, start = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') st.push(i);
            else
            {
                if (st.empty())
                {// no matching left parenthesis, start over
                    start = i;
                }
                else
                {
                    // find a matching pair
                    st.pop();
                    if (st.empty())
                    {// find the distance to the last unmatched cell
                        maxlen = max(maxlen, i-start);
                    }
                    else
                    {// find the distance to the nearest unmatched left parenthesis
                        maxlen = max(maxlen, i-st.top());
                    }
                }
            }
        }
        return maxlen;
    }
};
