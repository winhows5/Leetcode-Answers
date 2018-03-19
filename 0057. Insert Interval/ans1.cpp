/* time cost: 9ms (99.91%) */
/* time complexity: O(n)   */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *   d  Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int start = newInterval.start;
        int end = newInterval.end;
        vector<Interval> ans;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].end < start) {
                ans.push_back(intervals[i]);
            }
            else if (intervals[i].start > end) {
                ans.push_back(Interval(start, end));
                copy(intervals.begin() + i, intervals.end(), back_inserter(ans));
                return ans;
            }
            else {
                start = min(start, intervals[i].start);
                end = max(end, intervals[i].end);
            }
        }
        ans.push_back(Interval(start, end));
        return ans;
    }
};
