

class Solution {
public:
    int findMaxProfit(int i, int canBuy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (k == 0 || i == prices.size()) return 0;
        
        if (dp[i][canBuy][k] != -1) return dp[i][canBuy][k];   
        
        int maxProfit = 0;
        if (canBuy) {
            int buy = -prices[i] + findMaxProfit(i + 1, 0, k, prices, dp);
            int notbuy = 0 + findMaxProfit(i + 1, 1, k, prices, dp);
            maxProfit = max(buy, notbuy);
        } else {
            int sell = prices[i] + findMaxProfit(i + 1, 1, k - 1, prices, dp);
            int notsell = 0 + findMaxProfit(i + 1, 0, k, prices, dp);
            maxProfit = max(sell, notsell);  
        }
        return dp[i][canBuy][k] = maxProfit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0; // If there are less than 2 prices, no transaction can be made
        
        // If k is greater than half of the total number of days, it's equivalent to making transactions as many times as possible
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return findMaxProfit(0, 1, k, prices, dp);
    }
};

