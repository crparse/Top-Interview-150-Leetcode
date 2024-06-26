class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> result(2, -1);
        
        while (left <= right) {
            int mid = right + (left - right) / 2;
            
            if (nums[mid] == target) {
                result[0] = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        left = 0;
        right = nums.size() - 1;
        
        while (left <= right) {
            int mid = right + (left - right) / 2;
            
            if (nums[mid] == target) {
                result[1] = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};
