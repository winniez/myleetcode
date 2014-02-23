/*
3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
/*
JAN 15 2014
Solution: Similar to 3 sum. Fix the first one and search the middle and last. 
Time complexity: O(n^2)
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int tmpsum=0, sum=0, tmpdist=INT_MAX, dist=INT_MAX;
        int mid, end;
        if (num.size()<3) return sum;
        sort(num.begin(), num.end());
        for (int start = 0; start <= num.size()-3; start++)
        {
            mid = start+1;
            end = num.size()-1;
            while(mid < end)
            {
                tmpsum = num[start] + num[mid] + num[end] - target;
                tmpdist = abs(tmpsum);
                if(dist>tmpdist)
                {
                    dist = tmpdist;
                    sum = tmpsum+target;
                }
                if (tmpsum<0)
                {
                    mid++;
                }
                else if (tmpsum>0)
                {
                    end--;
                }
                else
                {
                    break;
                }
            }
        }
        return sum;
    }
};
