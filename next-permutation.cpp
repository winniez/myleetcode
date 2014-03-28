/*
Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/*
Mar 27 2014
Solution:
1. From right to left, find the first digit that violate the increase trend;
2. From right to left, find the first digit which larger than the violation number, call it changenumber;
3. Swap the violation number and the changenumber;
4. reverse all the digits on the right of violation index.
Note:
Note the case when violation number is not found. Which indicates that the input is the largest possible permutation. The result should be wrapped to the smallest possible case. A ascending sort should solve the case.
Time O(n) space constant.
Reference:
http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size(), tmp;
        int violation = -1, firstlarger = - 1;
        for(int i = size-1; i>0; i--)
        {
            if(num[i-1] < num[i])
            {
                violation = i-1;
                break;
            }
        }
        if (violation == -1)
        {
            sort(num.begin(), num.end());
            return;
        }
        for(int i = size-1; i >= 0; i--)
        {
            if (num[i] > num[violation])
            {
                firstlarger = i;
                break;
            }
        }
        // swap
        tmp = num[violation];
        num[violation] = num[firstlarger];
        num[firstlarger] = tmp;
        // reverse
        int start = violation+1, end = size - 1;
        while(start<end)
        {
            tmp = num[start];
            num[start] = num[end];
            num[end] = tmp;
            start++;
            end--;
        }
    }
};
