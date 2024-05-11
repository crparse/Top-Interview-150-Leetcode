class Solution {
public:
    
    void helper(vector<string> &v, int n, int openCount, int closeCount, string s){
        //base case
        if(openCount == n && closeCount == n){
            v.push_back(s);
            return;
        }
        
        if(openCount < n){
            helper(v, n, openCount + 1, closeCount, s+"(");
        }
        
        if(closeCount < openCount){
            helper(v, n, openCount, closeCount + 1, s+")");
        }
    
    }
    
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> v;
        int openCount = 0, closeCount = 0;
        helper(v, n, openCount, closeCount, "");
        return v;
    }
};
