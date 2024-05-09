class Solution {
public:
    
    // Helper function to recursively check if s3 is formed by interleaving s1 and s2
    bool isInterleave_helper(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &m){
        
        // If the result for the current indices i and j is already computed, return it
        if(m[i][j]!=-1) return m[i][j];
        
        // If we have reached the end of all strings, return true
        if(i==s1.length() && j==s2.length() && k==s3.length()) return true;
        
        // Initialize variables to track if we can move forward by picking characters from s1 or s2
        bool x=false, y=false;
        
        // If there are characters remaining in s1 and the current character in s1 matches s3, try picking it
        if(i!=s1.length()){
            if(s1[i]==s3[k]){
                x=isInterleave_helper(s1, s2, s3, i+1, j, k+1, m);
            }   
        }
        
        // If there are characters remaining in s2 and the current character in s2 matches s3, try picking it
        if(j!=s2.length()){
            if(s2[j]==s3[k]){
                y=isInterleave_helper(s1, s2, s3, i, j+1, k+1, m);
            }   
        }
        
        return m[i][j]=x||y;
    }
    
    // Main function to check if s3 is formed by interleaving s1 and s2
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.length(),b=s2.length();
        vector<vector<int>> m(a+1,vector<int>(b+1,-1));
        return isInterleave_helper(s1, s2, s3, 0, 0, 0, m);
    }
};
