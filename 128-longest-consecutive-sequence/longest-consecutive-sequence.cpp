#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> sets(nums.begin(), nums.end());
        int ans = 0;
        for (int num : nums) {
            if (sets.find(num) == sets.end()) // Check if num is already visited
                continue;
            
            sets.erase(num); // Remove num from the set to avoid redundant checks
            
            int prev = num - 1;
            int next = num + 1;
            
            // Find consecutive numbers greater than num
            while (sets.find(next) != sets.end()) {
                sets.erase(next);
                ++next;
            }
            // Find consecutive numbers smaller than num
            while (sets.find(prev) != sets.end()) {
                sets.erase(prev);
                --prev;
            }
            // Calculate the length of the consecutive sequence
            ans = std::max(ans, next - prev - 1);
        }
        return ans;
    }
};
