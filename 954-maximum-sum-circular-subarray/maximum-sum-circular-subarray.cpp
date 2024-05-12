// 1ST APPROACH 

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int n = nums.size();
        
        // Case 1: Maximum subarray sum using Kadane's algorithm
        int max_sum = INT_MIN;
        int current_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            current_sum = std::max(nums[i], current_sum + nums[i]);
            max_sum = std::max(max_sum, current_sum);
        }
        
        // Case 2: Maximum subarray sum with circular wrapping
        int total_sum = 0;
        int min_sum = INT_MAX;
        int min_sum_temp = 0;
        
        for (int i = 0; i < n; ++i) {
            total_sum += nums[i];
            min_sum_temp = std::min(nums[i], min_sum_temp + nums[i]);
            min_sum = std::min(min_sum, min_sum_temp);
        }
        
        int max_circular_sum = total_sum - min_sum;
        
        // Handle case where all elements are negative
        if (max_circular_sum == 0) {
            return max_sum;
        }
        
        return std::max(max_sum, max_circular_sum);
    }
};

// 2ND APPROACH 

// class Solution {
// public:

//     int kadane(vector<int>& nums) {
//         int Maxsofar = INT_MIN;
//         int currmax = 0;
//         for(auto i:nums){
//             currmax += i;
//             if(currmax >Maxsofar){
//                 Maxsofar = max(Maxsofar,currmax);
//             }
//             if(currmax<0) currmax =0;
            
//         }return Maxsofar;
        
//     }

//     int maxSubarraySumCircular(vector<int>& nums) {
//         int maxsubarraySum = kadane(nums);
        
//         // reverse the nums vector and then calculate the maxsum_array. == minsum_array of orignal.
//         int countpositive =0;
//         int total_sum_reverse =0;
//         int minvalue_reverse =INT_MAX;
        

//         for(int i=0;i<nums.size();i++){
//              nums[i]= -1*nums[i];
//             //  count positive == count negative .
//              if(nums[i]>0){countpositive++;}
//              total_sum_reverse +=nums[i];
//              minvalue_reverse = min(minvalue_reverse,nums[i]);
//         }
//         if(countpositive == nums.size()){
//             return -1*(minvalue_reverse);
//         }
//         int maxsubarraySum_reverse = kadane(nums);
//         int reverse_ans = -1 * (total_sum_reverse - maxsubarraySum_reverse);
//         return max(maxsubarraySum,reverse_ans);
        
//     }
// };