/*
Remove Element Total Accepted: 7386 Total Submissions: 22470 My Submissions
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

/*
Feb. 3 2014
Note: we cannot move next element into a cell before checking what the next element is.
[2,2,3] 2, need to handle continous element cases

Solution:
scan and fill
maintain 2 pointers will be enough

less elegant----
maintain 3 pointers
i - scan pointer
j - range of identical elment pointer from i
k - fill pointer
note:
when jumping out of inner loop, A[j] ! = elem and j is already scan, next time move i to j + 1
when never inters inner loop, A[i] != elem and copy A[i] to current filling pointer

Time complexity: O(n)
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (!n) return 0;
        int cnt = 0;
        int i = 0, j = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] != elem)
            {
                A[j] = A[i];
                j++;
            }
        }
        return j;
    }
};

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (!n) return 0;
        int cnt = 0;
        int i = 0, j = 0, k = 0;
        // i - scan pointer
        // j - range of identical element pointer
        // k - write pointer
        while (i < n)
        {
            j = i;
            while(A[j] == elem && j < n)
            {
                cnt++;
                j++;
            }
            if (i == j)
            {
                A[k] = A[i];
                i++;
            }
            else
            {
                if (j < n)
                {
                    A[k] = A[j];
                }
                i = j+1;
            }
            k++;
        }
        return n-cnt;
    }
};
