class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        for(int i=0; i<s.size(); i++){
            char ch1=s[i];
            char ch2=t[i];
            if(mp1.find(ch1-'a') != mp1.end() || mp2.find(ch2-'a') != mp2.end()){
                if(mp1[ch1-'a'] != ch2-'a' || mp2[ch2-'a'] != ch1-'a'){
                    return false;
                }
            }
            else{
                mp1[ch1-'a'] =ch2-'a';
                mp2[ch2-'a']=ch1-'a';
            }
            
           
        }
        return true;
    }
};