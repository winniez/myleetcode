/*
Max Points on a Line
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
/*
Feb 17 2014
Solution:
2 points determines a line. If line(A,B) share same slope with (A,C), we can conclude A, B and C are on the same line. Use unordered_map (hashtable) to keep slope and appearance of each slope value.
This solution: Time O(n^2), space O(n).
Further, (Ya-Yb)/(Xa-Xb) == (Ya-Yc)/(Xa-Xc) => (Ya-Yb)*(Xa-Xc) == (Ya-Yc)*(Xa-Xb), in this way we avoid checking the same point and parallel to Y axis situation.
This solution: Time O(n^3) space constant
https://github.com/starcroce/leetcode/blob/master/max_points_on_a_line.cpp

1. let points[i] be the center
2. points[i] and points[j] determines a line, compute the slope.
3. compute slope for all j \belongs {i:n}, use slope as key, keep the number of appearance of slope.
4. keep track of the max value of unordered_map.
5. the global max is the sum of local max + number of same points.
Reference:
http://www.cnblogs.com/TenosDoIt/p/3444086.html
*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.empty()) return 0;
        double slope;
        unordered_map<double, int> slopes;
        int maxcnt = 0, localmaxcnt = 1, samepoint = 0;
        for (int i = 0; i < points.size(); i++)
        {
            slopes.clear();
            localmaxcnt = 1;
            samepoint = 0;
            for (int j = i+1; j < points.size(); j++)
            {
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                {
                    samepoint++;
                }
                else
                {
                    if (points[i].x - points[j].x == 0)
                    {
                        slope = 999999.99;
                    }
                    else
                    {
                        slope = (double)(points[i].y - points[j].y)/(double)(points[i].x - points[j].x);
                    }
                    if (!slopes.count(slope))
                    {
                        slopes[slope] = 1;
                    }
                    slopes[slope]++;
                    if (localmaxcnt < slopes[slope]) localmaxcnt = slopes[slope];
                }
            }
            if (maxcnt < localmaxcnt + samepoint) maxcnt = localmaxcnt + samepoint;
        }
        return maxcnt;
    }
};
