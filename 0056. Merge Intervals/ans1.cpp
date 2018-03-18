/* time cost: 9ms (100.00%)  */
/* time complexity: O(nlogn) */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        for (int i = 0; i < intervals.size(); ++i) {
            int start = intervals[i].start;
            int end = intervals[i].end;
            
            while (i+1 < intervals.size() && end >= intervals[i+1].start) {
                if (end >= intervals[i+1].end) {
                    ++i;
                    continue;
                }
                end = intervals[i+1].end;
            }
            ans.push_back(Interval(start, end));
        }
        return ans;
    }
};
