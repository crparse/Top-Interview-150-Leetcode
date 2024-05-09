#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        // Convert integer to string
        std::string str = std::to_string(x);
        
        int left = 0;
        int right = str.length() - 1;
        
        // Compare characters from both ends
        while (left < right) {
            if (str[left] != str[right]) {
                return false; // If characters don't match, it's not a palindrome
            }
            left++;
            right--;
        }
        
        return true; 
    }
};
