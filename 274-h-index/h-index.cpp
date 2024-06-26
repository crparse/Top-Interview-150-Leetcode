class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> count(n+1, 0);
        for(int citation: citations){
            if(citation >= n) count[n]++;
            else count[citation]++;
        }
        int papers = 0;
        for(int i=n; i>=0; i--){
            papers += count[i];
            if(papers >= i) return i;
        }
        return 0;
    }
};