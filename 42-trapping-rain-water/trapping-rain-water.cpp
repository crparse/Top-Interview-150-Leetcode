class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        // If there are no bars, no water can be trapped
        if(size == 0) return 0;
        
        // Arrays to store the maximum height of bars to the left and right of each position
        vector<int> maxl(size); // max height to the left
        vector<int> maxr(size); // max height to the right
        
        // Calculate the maximum height of bars to the left of each position
        maxl[0] = height[0];
        for(int i = 1; i < size; i++)
            maxl[i] = max(maxl[i - 1], height[i]);
        
        // Calculate the maximum height of bars to the right of each position
        maxr[size - 1] = height[size - 1];
        for(int i = size - 2; i >= 0; i--)
            maxr[i] = max(maxr[i + 1], height[i]);
        
        int water = 0; // Total trapped water
        
        // Calculate the trapped water at each position
        for(int i = 0; i < size; i++)
            water += (min(maxr[i], maxl[i]) - height[i]);
        
        return water; // Return total trapped water
    }
};
