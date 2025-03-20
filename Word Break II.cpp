class Solution {
    public:
        unordered_map<string, vector<string>> memo;
        
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
            return helper(s, wordSet);
        }
        
        vector<string> helper(string s, unordered_set<string>& wordSet) {
            if (memo.count(s)) return memo[s];
            if (s.empty()) return {""}; // Base case
            
            vector<string> result;
            
            for (int i = 1; i <= s.size(); i++) {
                string prefix = s.substr(0, i);
                if (wordSet.count(prefix)) {
                    vector<string> suffixWays = helper(s.substr(i), wordSet);
                    for (string suffix : suffixWays) {
                        result.push_back(prefix + (suffix.empty() ? "" : " " + suffix));
                    }
                }
            }
            
            return memo[s] = result;
        }
    };