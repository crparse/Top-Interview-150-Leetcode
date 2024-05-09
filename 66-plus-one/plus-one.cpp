#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        // Iterate over digits from right to left
        for (int i = n - 1; i >= 0; --i) {
            digits[i]++;
            if (digits[i] < 10) return digits;
            digits[i] = 0;  // If there's a carry, set the current digit to 0
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
