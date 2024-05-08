
class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        int maxArea = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    maxArea = std::max(maxArea, 1);
                }
            }
        }
        
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    maxArea = std::max(maxArea, dp[i][j] * dp[i][j]);
                }
            }
        }
        
        return maxArea;
    }
};
// class Solution {
// public:
//     int maximalSquare(std::vector<std::vector<char>>& matrix) {
//         if (matrix.empty() || matrix[0].empty()) return 0;
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
//         int maxSquareLen = 0;
        
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (matrix[i][j] == '1') {
//                     dp[i][j] = 1;
//                     maxSquareLen = std::max(maxSquareLen, 1);
//                 }
//             }
//         }
        
//         for (int i = 1; i < m; ++i) {
//             for (int j = 1; j < n; ++j) {
//                 if (matrix[i][j] == '1') {
//                     dp[i][j] = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
//                     maxSquareLen = std::max(maxSquareLen, dp[i][j]);
//                 }
//             }
//         }
        
//         return maxSquareLen * maxSquareLen;
//     }
// };
