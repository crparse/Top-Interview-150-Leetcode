class Solution {
public:
    int lengthOfLastWord(string s) {
       bool flag=false;
       int n=s.size();
       int count=0;
       for(int i=n-1; i>=0; i--){
            if(s[i] == ' ' && flag) break;
            else if(s[i] != ' '){
                count++;
                flag=true;
            }
        }
        return count; 
    }
};