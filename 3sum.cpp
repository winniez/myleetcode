/*
3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*/

/*
JAN 15 2014
Solution: DP, fix the first one, search the middle and last one.
Note: uniqueness!!!!
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > rtn;
        if (num.size()<3) return rtn;
        vector<int> triplet(3,0);
        // first sort input vector into ascending order
        sort(num.begin(), num.end());
        int start, mid, end, tmpsum;
        for (start = 0; start<=num.size()-3; start++)
        {
            // note uniqueness
            if (start > 0 && num[start] == num[start - 1])  continue;
            end = num.size()-1;
            mid = start + 1;
            while( mid < end)
            {
                tmpsum = num[start] + num[mid];
                if (tmpsum + num[end]>0)
                {end--;}
                else if (tmpsum + num[end]<0)
                {mid++;}
                else
                {
                    triplet[0] = num[start];
                    triplet[1] = num[mid];
                    triplet[2] = num[end];
                    rtn.push_back(triplet);
                    mid++;
                    end--;
                    // note uniqueness
                    while(num[mid-1]==num[mid] && mid < end)
                    {mid++;}
                    while(num[end+1]==num[end] && mid < end)
                    {end--;}
                }
            }
        }
        return rtn;
    }
};
