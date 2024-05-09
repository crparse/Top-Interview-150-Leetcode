class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; 
        int left = 1, right = x, ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) { // Checking if mid*mid <= x to avoid overflow
                ans = mid;
                left = mid + 1; // Search in the right half
            }
             else right = mid - 1; // Search in the left half
            
        }return ans;
    }
};
