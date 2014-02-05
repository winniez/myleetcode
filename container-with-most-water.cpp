/*
Container With Most Water
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
/*
Feb 4 2014
Reference:
http://www.cnblogs.com/lichen782/p/leetcode_Container_With_Most_Water.html
http://blog.unieagle.net/2012/09/16/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Acontainer-with-most-water/
Analysis:
Since i is lower than j, so there will be no jj < j that make the area from i,jj is greater than area from i,j. So the maximum area that can benefit from i is already recorded. Thus, we move i forward.
Time complexity: O(n), space constant.
*/
class Solution {
public:
int maxArea(vector<int> &height) {
        int areaMax = INT_MIN, areaCur;
        int start = 0, end = height.size() - 1;
        while(start < end)
        {
            areaCur = (end-start) * min(height[start], height[end]);
            if (areaCur > areaMax)
            {
                areaMax = areaCur;
            }
            if (height[start] < height[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return areaMax;
    }
/*
    int maxArea(vector<int> &height) {
        int areaMax = INT_MIN;
        int areaCur;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i+1; j < height.size(); j++)
            {
                areaCur = (j-i)*min(height[i], height[j]);
                if (areaCur > areaMax)
                {
                    areaMax = areaCur;
                }
            }
        }
        return areaMax;
    }
*/
};
