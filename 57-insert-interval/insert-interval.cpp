class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans; // Initialize a vector to store the merged intervals

        // Iterate through each interval in the given intervals
        for(auto interval : intervals){
            // If the end of the current interval is before the start of the new interval
            if(interval[1] < newInterval[0]){
                ans.push_back(interval); // Add the current interval to the answer
            } 
            // If the start of the current interval is after the end of the new interval
            else if(interval[0] > newInterval[1]){
                ans.push_back(newInterval); // Add the new interval to the answer
                newInterval = interval; // Update the new interval to the current interval
            }
            else{
                // If there is an overlap between the current interval and the new interval,
                // update the start and end of the new interval to cover both intervals
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        ans.push_back(newInterval); // Add the final merged interval to the answer
        return ans; // Return the merged intervals
    }
};
