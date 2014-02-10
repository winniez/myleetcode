/*
Implement strStr()
Implement strStr().
Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/
/*
Feb 10 2014
Solution:
- scan, i points to character in haystack, j points to character in needle.
-- increment j when haystack[i] == needle[j], when reaches needle's end, return
-- when haystack[i] != needle[j], return i to the 2nd character of previously matched substring
Note:
int l_need = strlen(needle);
if(l_need == 0) return haystack;
int l_hay = strlen(haystack);
if(l_hay == 0)    return NULL;
*/
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (strlen(needle) == 0) return haystack;
        if (strlen(haystack) == 0) return NULL;
        int i = 0, j = 0;
        while(i < strlen(haystack))
        {
            if (haystack[i] == needle[j])
            {
                j++;
                if (j == strlen(needle))
                {
                    return &haystack[i-j+1];
                }
            }
            else
            {
                // return pointer to the 1st match, do not increment here
                i = i-j;
                j = 0;
            }
            // i increments
            i++;
        }
        return NULL;
    }
};
