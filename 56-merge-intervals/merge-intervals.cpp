class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals based on the starting points
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        // Iterate through sorted intervals
        for(const auto& interval : intervals) {
            // If merged is empty or current interval doesn't overlap with the last merged interval
            if (merged.empty() || interval[0] > merged.back()[1]) {
                merged.push_back(interval);
            } else { // If current interval overlaps with the last merged interval
                // Merge the intervals by updating the end point of the last merged interval
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};
