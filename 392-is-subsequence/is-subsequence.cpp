class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};




// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int i=0, j=0;
//         while(s[i] != '\0'){
//             while(s[i] != t[j] && t[j] != '\0'){
//                 i++;
//                 if(t[j]=='\0') break;
//                 i++;
//                 j++;
//             }
//             if(s[i]=='\0') return true;
//             else return false;
//         }
//     }
// };