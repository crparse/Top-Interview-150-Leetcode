class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                int min_val = std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                int sum = min_val + triangle[i][j];
                triangle[i][j] = sum;
            }
        }
        return triangle[0][0];
    }
};