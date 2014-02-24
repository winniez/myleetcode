/*
Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More pratice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

/*
Feb 23 2014
Solution:
* O(n) solution -- 1d dp. Scan from left to right, discard negative sum and record sum as current value. Record and max sum.
* divide and conquer. The find min value and split by min value method failed. We still need to check the situation when the result could be covering the middle.
- find maxsum for left to mid-1; find maxsum for mid+1 to right; find maxsum for range covering mid. Note the restrictioni for the 3rd situation is that mid have to be covered. Therefore we initiate the max sum till mid and max sum from mid to 0, if the actual max sum is negative, we could discard them and have a subarray only contains mid.

Reference:
http://jane4532.blogspot.com/2013/06/maximum-subarrayleetcode.html
http://fisherlei.blogspot.com/2012/12/leetcode-maximum-subarray.html
*/
class Solution {
public:
    // O(n) solution
    int maxSubArray(int A[], int n) {
        if (!n) return 0;
        int maxsum = A[0], localmaxsum = 0;
        for (int i = 0; i < n; i++)
        {
            localmaxsum = max(localmaxsum + A[i], A[i]);
            maxsum = max(maxsum, localmaxsum);
        }
        return maxsum;
    }
    // divide and conquer
    int maxSubArray(int A[], int n) {
        return maxSubArrayHelper(A, 0, n-1);
    }
    // divide and conquer
    int maxSubArrayHelper(int A[], int s, int e)
    {
        if (s>e) return INT_MIN;
        if (s==e) return A[s];
        int mid = (s+e)/2;
        int lmaxv = maxSubArrayHelper(A, s, mid-1);
        int rmaxv = maxSubArrayHelper(A, mid+1, e);
        int cursum = 0, lmax = 0, rmax = 0;
        for (int i = mid-1; i>=s; i--)
        {
            cursum += A[i];
            if (cursum > lmax) lmax = cursum;
        }
        cursum = 0;
        for (int i = mid+1; i<=e; i++)
        {
            cursum += A[i];
            if (cursum > rmax) rmax = cursum;
        }
        return max(lmax + A[mid] + rmax, max(lmaxv, rmaxv));
    }
}
