/*
Merge Sorted Array
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/
/*
Feb 24 2014
Solution:
- Merge sorted array A and B into A. Do not use extra space.
- Merge from right to left. In this way we won't fill in a cell where value is not sorted and compared yet.
Reference:
http://discuss.leetcode.com/questions/263/merge-sorted-array
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        while(n>0){
        if(m <=0 || A[m-1] < B[n-1])
            A[n+m-1] = B[--n];
        else
            A[n+m-1] = A[--m];
        }
    }
};

// my own version, less elegant
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m-1, j = n-1;
        while(j>=0)
        {
            if (i>=0)
            {
                if (A[i] > B[j])
                {
                    A[i+j+1] = A[i];
                    i--;
                }
                else
                {
                    A[i+j+1] = B[j];
                    j--;
                }
            }
            else
            {
                A[i+j+1] = B[j];
                j--;
            }
        }
    }
};
