class Solution {
public:
    // Helper function to calculate the minimum edit distance between word1 and word2
    int minDistanceHelper(string& word1, string& word2, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        
        // Base case: If word1 is empty, insert all characters from word2
        if (i == 0) {
            dp[i][j] = j;
            return j;
        }
        
        // Base case: If word2 is empty, delete all characters from word1
        if (j == 0) {
            dp[i][j] = i;
            return i;
        }
        
        // If the characters at current positions in word1 and word2 are same
        if (word1[i - 1] == word2[j - 1]) {
            // Move to the next characters without any operation
            dp[i][j] = minDistanceHelper(word1, word2, dp, i - 1, j - 1);
        } 
        else {
            // Otherwise, consider insert, delete, and replace operations
            int insertOp = minDistanceHelper(word1, word2, dp, i, j - 1);   
            int deleteOp = minDistanceHelper(word1, word2, dp, i - 1, j);   
            int replaceOp = minDistanceHelper(word1, word2, dp, i - 1, j - 1); 
            // Choose the minimum among the three operations and add 1 to it (for the current operation)
            dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }
        return dp[i][j];
    }
    
    // Main function to calculate the minimum edit distance between word1 and word2
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return minDistanceHelper(word1, word2, dp, m, n);
    }
};
;