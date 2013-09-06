/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator < (const Interval a, const Interval b) {
    return a.start < b.start;
}
    

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start > newInterval.end) {
                ret.push_back(intervals[i]);
                continue;
            }
            if (intervals[i].end < newInterval.start) {
                ret.push_back(intervals[i]);
                continue;
            }
            if (newInterval.start == -1 && newInterval.end == -1) {
                ret.push_back(intervals[i]);
                continue;
            }
            if (intervals[i].start <= newInterval.start) {
                newInterval.start = intervals[i].start;
                if (intervals[i].end >= newInterval.end) {
                    newInterval.end = intervals[i].end;
                    ret.push_back(newInterval);
                    newInterval.start = newInterval.end = -1;
                }
            } else {
                if (intervals[i].end  >=  newInterval.end) {
                    newInterval.end = intervals[i].end;
                    ret.push_back(newInterval);
                    newInterval.start = newInterval.end = -1;
                }
            }       
        }
        if (newInterval.start != -1) {
            ret.push_back(newInterval);
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};