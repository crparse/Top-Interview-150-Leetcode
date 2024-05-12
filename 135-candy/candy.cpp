class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);

        // Step 1: Calculate left candies
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // Step 2: Calculate right candies
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        // Step 3: Calculate total candies
        int total = 0;
        for (int i = 0; i < n; ++i) {
            total += max(left[i], right[i]);
        }
        
        return total; //retured total candies
    }
};