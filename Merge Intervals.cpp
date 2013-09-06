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
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        map<int, int> mm;
        map<int, int> rr;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            mm[intervals[i].start * 2] = 0;
            mm[intervals[i].start * 2+ 1] = 0;
            mm[intervals[i].end * 2] = 0;
            mm[intervals[i].end * 2 + 1] = 0;
        }
        int ll = 0;
        for (map<int, int>::iterator it = mm.begin(); it != mm.end(); ++it) {
            it ->second = ll++;
            rr[it -> second] = it -> first;
        }
        vector<int> hh;
        hh.resize(ll + 1);
        for (int i = 0; i < n; ++i) {
            ++hh[mm[intervals[i].start * 2]];
            --hh[mm[intervals[i].end * 2 + 1]];
        }
        int sum = 0;
        Interval in;
        in.start = in.end = -1;
        for (int i = 0; i <= ll; ++i) {
            if (sum == 0) {
                sum += hh[i];
                if (sum > 0) {
                    in.start = rr[i] / 2;
                }
                
            
            } else {
                sum += hh[i];
                if (sum == 0) {
                    in.end = rr[i - 1] / 2;
                    ret.push_back(in); 
                }
            }
        }
        return ret;
    }
};