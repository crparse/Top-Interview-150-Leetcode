// 1ST APPROACH 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }return dp[n];
    }
};



// 2ND APPRAOCH

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());
//         unordered_set<string> memo; // Memoization to store previously explored substrings
//         return dfs(s, dict, memo);
//     }
    
//     bool dfs(string& s, unordered_set<string>& dict, unordered_set<string>& memo) {
//         if (s.empty()) return true; // Base case: empty string can always be segmented
//         if (memo.find(s) != memo.end()) return false; // If the substring is already explored
//         for (int i = 1; i <= s.length(); ++i) {
//             string prefix = s.substr(0, i);
//             if (dict.find(prefix) != dict.end()) {
//                 string suffix = s.substr(i);
//                 if (dfs(suffix, dict, memo)) return true;
//             }
//         }
//         // If no valid segmentation found, add the substring to memoization set
//         memo.insert(s);
//         return false;
//     }
// };
