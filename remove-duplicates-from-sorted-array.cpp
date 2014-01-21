/*
Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/

/*
JAN 21 2014
Note how index is updated, as follower cells are already moved.
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
                start = index+1;
                end = next - 1;
                gap = next - index - 1;
                for (int i = index + 1; i < len-gap; i++)
                {
                    A[i] = A[i+gap];
                }
                len -= gap;
            }
            index = index + 1;
            next = index + 1;
        }
        return len;
    }
};
