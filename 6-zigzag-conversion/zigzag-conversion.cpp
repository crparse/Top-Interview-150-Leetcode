#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) return s;
        std::string result;
        int n = s.length();
        int cycleLen = 2 * numRows - 2; // Length of a single cycle in the zigzag pattern

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                result += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    result += s[j + cycleLen - i];
                }
            }
        }
        return result;
    }
};
