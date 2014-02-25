/*Merge Intervals
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
/*
Feb 24 2014
Solution:
* Use stl sort and a self defined compare func to sort (by start) input intervals.
* Merge overlapping interval; add non-overlapping interval into ouput vector.
Time: O(n*log n + n)
Note:
The self defined compare func should be defined outside the class defination. Otherwise stl sort need to call the func by an object.
Reference:
stl sort: http://www.cplusplus.com/reference/algorithm/sort/
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool IntervalComp(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> rtn;
        if (intervals.empty()) return rtn;
        sort(intervals.begin(), intervals.end(), IntervalComp);
        rtn.push_back(intervals[0]);
        int cur = 0, flag = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start > rtn[cur].end)
            {
                rtn.push_back(intervals[i]);
                cur++;
            }
            else if (intervals[i].end < rtn[cur].start)
            {
                rtn.push_back(intervals[i]);
                cur++;
            }
            else
            {
                rtn[cur].start = min(rtn[cur].start, intervals[i].start);
                rtn[cur].end = max(rtn[cur].end, intervals[i].end);
            }
        }
        return rtn;
    }
};
