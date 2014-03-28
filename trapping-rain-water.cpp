/*
Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

/*
Solution:
if we traverse the list from left to right, the amount of water at each index is at most the largest value we have discovered so far. That means that if we knew for a fact that there is something larger or equal to it somewhere on the right, we would know exactly how much water we can hold without spilling. Same goes for traversing in the opposite direction: if we know we have found something larger on the left than the largest thing on the right, we can safely fill up water.

With this in mind, one solution would be to first find the absolute maximum value, traverse from the left to the maximum, and then traverse from the right to the maximum. This solution does 2 passes: one to find the maximum, and the other is split into two subtraversals.

The solution in one pass (shown in the gist) avoids finding the maximum value by moving two pointers from the opposite ends of the array towards each other. If the largest value found to the left of the left pointer is smaller than the largest value found to the right of the right pointer, then move the left pointer one index to the right. Otherwise move the right pointer one index to the left. Repeat until the two pointers intersect. (This is a wordy explanation, but the code is really simple)
Reference:
http://qandwhat.apps.runkite.com/i-failed-a-twitter-interview/
https://gist.github.com/mkozakov/59af0fd5bddbed1a0399
One pass solution - Time O(n), space O(1).
Two pass solution - Time O(n), space O(n).
*/
class Solution {
public:
    int trap(int A[], int n) {
        if (!A || !n) return 0;
        if (n < 2) return 0;
        int leftMax = 0, rightMax = 0, left = 0, right = n-1;
        int trapped = 0;
        while(left < right)
        {
            if (A[left] > leftMax) leftMax = A[left];
            if (A[right] > rightMax) rightMax = A[right];
            if (leftMax <= rightMax)
            {
                trapped += leftMax - A[left];
                left++;
            }
            else
            {
                trapped += rightMax - A[right];
                right--;
            }
        }
        return trapped;
    }
};
