#include <vector>
using namespace std;

class Solution {
    void generateSubsets(int start, int n, vector<int>& current, vector<vector<int>>& Subsets, int k) {
        if (current.size() == k) {
            Subsets.push_back(current);
            return;
        }
        for (int i = start; i <= n; i++) {
            current.push_back(i); // on add 
            generateSubsets(i + 1, n, current, Subsets, k);
            current.pop_back(); // extra one removed
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> Subsets;
        vector<int> current;
        generateSubsets(1, n, current, Subsets, k);
        return Subsets;
    }
};
