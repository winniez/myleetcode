/*
Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

/*
Solution:
- build a new string s1, only take alpha + numeric characters, convert higher case to lower case.
- use start and end pointer to scan s1.
Note:
alpha + numeric characters
*/
class Solution {
public:
    bool isPalindrome(string s) {
        //convert string
        string s1;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i]>='a' && s[i] <= 'z') s1 += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z') s1 += s[i] - 'A' + 'a';
            else if(s[i] >= '0' && s[i] <= '9') s1 += s[i];
        }
        int start = 0, end = s1.size()-1;
        while(start<end)
        {
            if(s1[start] != s1[end]) return false;
            start++; end--;
        }
        return true;
    }
};
