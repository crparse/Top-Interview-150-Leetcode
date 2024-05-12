class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        int ans=INT_MAX;
        while(left <= right){
            int mid=(left+right)/2;
            if(nums[left] <= nums[mid]){
                ans=min(ans,nums[left]);
                left=mid+1;
            }
            else{
                right = mid-1;
                ans=min(ans,nums[mid]);
            }
        }
        return ans;
    }
};