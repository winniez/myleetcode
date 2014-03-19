/*
Largest Rectangle in Histogram
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/
/*
Feb 12 2014
Solution:
O(n)
1) Create an empty stack.
2) Start from first bar, and do following for every bar ‘hist[i]‘ where ‘i’ varies from 0 to n-1.
……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).
3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.
Reference:
http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
http://dp2.me/blog/?p=482
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) return 0;
        int n = height.size();
        // Create an empty stack. The stack holds indexes of hist[] array
        // The bars stored in stack are always in increasing order of their
        // heights.
        stack<int> s;
        int i = 0, areamax = 0, area_with_top;
        int tp;  // To store top of stack
        // Run through all bars of given histogram
        while(i<n)
        {
            // If this bar is higher than the bar on top stack, push it to stack
            if (s.empty() || height[s.top()] <= height[i])
            {
                s.push(i);
                i++;
            }
            else
            // If this bar is lower than top of stack, then calculate area of rectangle
            // with stack top as the smallest (or minimum height) bar. 'i' is
            // 'right index' for the top and element before top in stack is 'left index'
            {
                tp = s.top();
                s.pop();
                // Calculate the area with hist[tp] stack as smallest bar
                area_with_top = height[tp] * (s.empty()? i: i-s.top()-1);
                areamax = max(areamax, area_with_top);
            }
        }
        // Now pop the remaining bars from stack and calculate area with every
        // popped bar as the smallest bar
        while(!s.empty())
        {
            tp = s.top();
            s.pop();
            area_with_top = height[tp]*(s.empty()?i:i-s.top()-1);
            areamax = max(areamax, area_with_top);
        }
        return areamax;
    }
};

