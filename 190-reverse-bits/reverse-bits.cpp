#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (n & 1); // Shift result left and add the least significant bit of n
            n >>= 1; // Shift n to the right by 1
        }
        return result;
    }
};
