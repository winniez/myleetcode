/*
Insert Interval
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/*
Feb 10 2014
Solution:
- scan list from front to end and search for the first non-overlaping larger interval -> end
- scal list from end to front and search for the first non-overlaping smaller interval -> begin
- handle no overlapping situation, end < begin
- handle overlapping situation, generate new interval, remove the overlapping intervals, which indexing begin ... end.

Time: O(n)
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
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int n = intervals.size();
        int begin = n;
        int end = -1;
        for (int i = 0; i < n; i++)
        {
            if (newInterval.end >= intervals[i].start)
            {
                end = i;
                // intervals[end+1] will have no overlap with newInterval
            }
        }
        for (int i = n-1; i >=0; i--)
        {
            if (newInterval.start <= intervals[i].end)
            {
                begin = i;
                // intervals[begin-1] will have no overlap with newInterval
            }
        }
        // check if overlap area
        if (end == -1)
        {// new interval is smaller than anyother interval and has no overlap
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        if (begin == n)
        {// new interval is larger than anyother interval and has no overlap
            intervals.insert(intervals.end(), newInterval);
            return intervals;
        }
        Interval p(min(newInterval.start, intervals[begin].start), max(newInterval.end, intervals[end].end));
        intervals.erase(intervals.begin()+begin, intervals.begin()+end+1);
        intervals.insert(intervals.begin()+begin, p);
        return intervals;
    }
};

// another solution
// copy non-overlapping ones into new list, then iteratively merge with overlapping ones into newInterval, until no overlapping
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        bool isLarge = true;
        for (vector<Interval>::iterator it = intervals.begin();
            it != intervals.end();
            ++ it)
        {
            if (it->end < newInterval.start)
            {
                result.push_back(*it);
                continue;
            }
            if (it->start > newInterval.end)
            {
                if (isLarge)
                {
                    result.push_back(newInterval);
                    isLarge = false;
                }
                result.push_back(*it);
                continue;
            }
            newInterval.start = (it->start < newInterval.start) ? 
                it->start : newInterval.start;
            newInterval.end = (it->end > newInterval.end) ?
                it->end : newInterval.end;
        }
        if (isLarge)
            result.push_back(newInterval);
        return result;
    }
};
