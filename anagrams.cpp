/*
Anagrams
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

/*
JAN 17 2014
Analysis:
Anagrams is two strings are using the same characters.
One way to compare two strings is use sort()
1. Scan the whole string vector, for each string, store to a hash map with the "ordered string" as the key. O(n).
2. Scan the whole hash map, output the values where for one key the number of value >=2. O(n)

Note: Use one map <sorted string as the key,  position of the first string(unsorted)>, can deal with this problem more space efficiently.

Reference:
http://yucoding.blogspot.com/2012/12/leetcode-quesion-6-anagram.html
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> rtn;
        string tmp;
        if (strs.empty()) return rtn;
        map<string, vector<string> > table;
        for (int i = 0; i < strs.size(); i++)
        {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (table.find(tmp) == table.end())
            {
                vector<string> list;
                list.push_back(strs[i]);
                table[tmp] = list;
            }
            else
            {
                table[tmp].push_back(strs[i]);
            }
        }
        map<string, vector<string> >::iterator it;
        for(it = table.begin(); it != table.end(); ++it)
        {
            if (it->second.size()>1)
            {
                rtn.insert(rtn.end(), it->second.begin(), it->second.end());
            }
        }
        return rtn;
    }
};

class Solution1 {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> rtn;
        string tmp;
        if (strs.empty()) return rtn;
        map<string, vector<int> > table;
        for (int i = 0; i < strs.size(); i++)
        {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (table.find(tmp) == table.end())
            {
                vector<int> list;
                list.push_back(i);
                table[tmp] = list;
            }
            else
            {
                table[tmp].push_back(i);
            }
        }
        map<string, vector<int> >::iterator it;
        for(it = table.begin(); it != table.end(); ++it)
        {
            if (it->second.size()>1)
            {
                for (int i = 0; i<it->second.size(); i++)
                {
                    rtn.push_back(strs[it->second[i]]);
                }
            }
        }
        return rtn;
    }
};
