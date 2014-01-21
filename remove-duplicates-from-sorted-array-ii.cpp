/*
Remove Duplicates from Sorted Array II
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

/*
JAN 21 2014
Note: similar to Remove Duplicates from Sorted Array, expect gap is gap-1 in this case.
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int len = n;
        int index = 0;
        int next = index+1;
        int start, end, gap;
        bool duplicate;
        while (next < len)
        {
            duplicate = false;
            while(A[index] == A[next])
            {
                duplicate = true;
                next++;
                if (next == len) break;
            }
            if (duplicate)
            {
                gap = next - index - 1;
                if (gap > 1)
                {
                    for (int i = index + 2; i < len-gap+1; i++)
                    {
                        A[i] = A[i+gap-1];
                    }
                    len = len - gap + 1;
                }
            }
            index = index + 1;
            next = index + 1;
        }
        return len;
    }
};
