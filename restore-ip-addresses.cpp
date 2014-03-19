/*
Restore IP Addresses
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
/*
Mar 18 2014
Solution:
dynamic programming.
For each section, try len of 1, 2 or 3. Note to validate the selected sub string. Substring of size 3 must not smaller than 100 as 010 is not valid. Substring of size 2 must not smaller than 10 as 09 is not valid.
Add built string to output set only if all 4 sections have been generated and we have utilized the entire input string.
Reference
http://yucoding.blogspot.com/2013/04/leetcode-question-83-restore-ip.html
*/

class Solution {
public:
    bool validate(string s)
    {
        if(s.empty()) return false;
        if (s.size() == 3)
        {
            if (atoi(s.c_str())>255 || atoi(s.c_str()) < 100) return false;
        }
        if (s.size() == 2)
        {
            if (atoi(s.c_str()) < 10) return false;
        }
        // 0.0.0.0 is leagal
        return true;
    }
    
    void dp(string rest, string built, vector<string>&res, int section)
    {
        if (section == 0)
        {
            if (rest.empty()) res.push_back(built);
            return;
        }
        else
        {
            // section of size 1, 2 or 3
            for(int i = 1; i <= 3; i++)
            {
                if (rest.size() >= i && validate(rest.substr(0, i)))
                {
                    if (section == 1) dp(rest.substr(i), built+rest.substr(0,i), res, section-1);
                    else dp(rest.substr(i), built+rest.substr(0,i)+".", res, section-1);
                }
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> rtn;
        int len = s.size();
        dp(s, "", rtn, 4);
        return rtn;
    }
};
