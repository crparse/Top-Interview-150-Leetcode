class Solution {
public:
    int singleNumber(vector<int>& nums){
        int firstCount = 0, secondCount = 0;
        for(int num: nums){
            firstCount = (firstCount ^ num) & (~secondCount);
            secondCount = (secondCount ^ num) & (~firstCount);
        }
        return firstCount;
    }
};
