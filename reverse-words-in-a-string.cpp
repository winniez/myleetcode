/*
Reverse Words in a String
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
/*
Solution:
a. reverse the entire input string
b. find word in string, reverse the word and append to a new string.
Note:
do not lose the last word if the string not ending with space.
*/

class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty()) return;
        // reverse entire string
        int begin = 0, end = s.size()-1;
        char tmp;
        while(begin < end)
        {
            tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            begin++; end--;
        }
        // reverse word
        string news;
        int wordbegin = -1, firstspace = -1, b, e;
        if (s[0] != ' ') wordbegin = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != ' ' && s[i-1] == ' ') wordbegin = i;
            if (s[i] == ' ' && s[i-1] != ' ')
            {
                firstspace = i;
                b = wordbegin, e = firstspace-1;
                while(b < e)
                {
                    tmp = s[b];
                    s[b] = s[e];
                    s[e] = tmp;
                    b++; e--;
                }
                if (!news.empty()) news += ' ';
                news.append(s, wordbegin, firstspace-wordbegin);
            }
        }
        if (firstspace < wordbegin)
        {
            b = wordbegin, e = s.size()-1;
            while(b < e)
            {
                tmp = s[b];
                s[b] = s[e];
                s[e] = tmp;
                b++; e--;
            }
            if (!news.empty()) news += ' ';
            news.append(s, wordbegin, s.size()-wordbegin);
        }
        s = news;
    }
};
