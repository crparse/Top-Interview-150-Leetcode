class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int, int> diffs;

        for(int i = 0; i < nums.size(); ++i) {
            int value = nums[i];

            auto found = diffs.find(value);
            if(found != diffs.end()) {
                return std::vector<int>{found->second, i};
            }

            diffs[target - value] = i;
        }

        return std::vector<int>();
    }
};