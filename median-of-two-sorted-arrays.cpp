/*
Median of Two Sorted Arrays
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
/*
Feb 27 2014
Solution:
1. A version of find kth element in the join of 2 sorted arrays.
http://fisherlei.blogspot.com/2012/12/leetcode-median-of-two-sorted-arrays.html
Each time discard half of A or B.

If (m/2+n/2+1) > k && am/2 > bn/2 , drop Section am/2~am-1
If (m/2+n/2+1) > k && am/2 < bn/2 , drop Section bn/2~bn-1
If (m/2+n/2+1) < k && am/2 > bn/2 ,  drop Section b0~bn/2
If (m/2+n/2+1) < k && am/2 < bn/2 ,  drop Section a0~am/2

Note: n-(n/2+1) is different from n/2-1 as the divide will floor to int.

Time O(log m + log n)
logm + logn = log(mn)  <= log( (m + n)  ^ 2) =2 log(m + n)  = O(log(m + n))

2. Binary search
http://leetcode.com/2011/03/median-of-two-sorted-arrays.html

http://www2.myoops.org/course_material/mit/NR/rdonlyres/Electrical-Engineering-and-Computer-Science/6-046JFall-2005/30C68118-E436-4FE3-8C79-6BAFBB07D935/0/ps9sol.pdf

Abandon half of the 2 array each time. A lot of corner cases....
*/

// Solution 1: a special case of find kth element in the union of 2 sorted arrays
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = (m + n)/2+1;
        if ((m+n)%2)
        {// odd
            return findKthSortedArrays(A, m, B, n, k);
        }
        else
        {// even
            return (findKthSortedArrays(A, m, B, n, k-1) + findKthSortedArrays(A, m, B, n, k))/2.0;
        }
    }
    double findKthSortedArrays(int A[], int m, int B[], int n, int k)
    {
        if (m <= 0) return B[k-1];
        if (n <= 0) return A[k-1];
        if (k <= 1) return min(A[0], B[0]); 
        if (A[m/2] <= B[n/2])  
        {
            if (m/2 + n/2 + 1 >= k)
            {
                return findKthSortedArrays(A, m, B, n/2, k);
            }
            else
            {
                return findKthSortedArrays(A+m/2+1, m-(m/2+1), B, n, k-(m/2+1));
            }
        }
        else
        {// A[m/2] > B[n/2]
            if (m/2 + n/2 + 1 >= k)
            {
                return findKthSortedArrays(A, m/2, B, n, k);
            }
            else
            {
                return findKthSortedArrays(A, m, B+n/2+1, n-(n/2+1), k-(n/2+1));
            }
        }
    }
};

double findMedian(int A[], int B[], int l, int r, int nA, int nB) {
        if (l > r)
            return findMedian(B, A, max(0, (nA+nB)/2-nA), min(nB, (nA+nB)/2), nB, nA);
        int i = (l+r)/2;
        int j = (nA+nB)/2 - i - 1;
        if (j >= 0 && A[i] < B[j])      // median > A[i]
            return findMedian(A, B, i+1, r, nA, nB);
        else if (j < nB-1 && A[i] > B[j+1]) // median < A[i]
            return findMedian(A, B, l, i-1, nA, nB);
        else                                // median == A[i]
        {
            if ( (nA+nB)%2 == 1 ) return A[i];
            else if (i > 0) return (A[i]+max(B[j], A[i-1]))/2.0;
            else return (A[i]+B[j])/2.0;
        }
    }
