
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int n = intervals.size();
        int start = newInterval[0];
        int end = newInterval[1];
        int i = 0;

        // Step 1: Add intervals before newInterval
        while (i < n && intervals[i][1] < start) {
            res.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals
        while (i < n && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }

        res.push_back({start, end});

        // Step 3: Add remaining intervals
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
