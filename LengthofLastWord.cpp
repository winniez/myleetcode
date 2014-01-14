/*
Length of Last Word Total Accepted: 4249 Total Submissions: 15685 My Submissions
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/

/*
JAN 13 2014
Solution:
- find the length of string;
- traverse backwards, find the last non-space character, record the index;
- then find the space character ahead of the last non-space character.

Edge Cases:
"", " ", "a"
if can not find last non-space character or the space character ahead of the last non-spce character...
Initialization of start and end, and cases. 
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (!s) return 0;
        if (!strlen(s)) return 0;
        // find out length
        int len = 0;
        int i = 0;
        while(s[i])
        {
            i++;
        }
        len = i;
        // traverse backwards from last character
        int start = -1, end = len-1, set = -1;
        for (i = len - 1; i >=0; i--)
        {
            if (s[i]!=' ')
            {
                if (set < 0)
                {
                    end = i;
                    set = 1;
                }
            }
            if (s[i]==' ')
            {
                if (set > 0)
                {
                    start = i;
                    break;
                }
            }
        }
        if (set > 0)
        {
            return end-start;
        }
        else
        {
            return 0;
        }
    }
};

