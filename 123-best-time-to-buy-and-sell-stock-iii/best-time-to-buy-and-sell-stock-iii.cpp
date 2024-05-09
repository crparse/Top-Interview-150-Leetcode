class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size < 2) return 0;
        
        int buyPrice = prices[0], sellPrice = prices[size - 1];
        vector<int> leftProfits(size, 0);
        vector<int> rightProfits(size, 0);
        
        for(int i = 1; i < size; ++i){
            leftProfits[i] = max(leftProfits[i - 1], prices[i] - buyPrice);
            buyPrice = min(buyPrice, prices[i]);
            
            int j = size - 1 - i;
            rightProfits[j] = max(rightProfits[j + 1], sellPrice - prices[j]);
            sellPrice = max(sellPrice, prices[j]);
        }
        
        int totalProfit = 0;
        for(int i = 0; i < size; ++i)
            totalProfit = max(totalProfit, leftProfits[i] + rightProfits[i]);
        return totalProfit;
    }
};
