class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0) {
            return false;
        }

        vector<bool> res(s.size() + 1, false);
        res[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (res[j]) {
                    string word = s.substr(j, i - j);
                    if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                        res[i] = true;
                        break;
                    }
                }
            }
        }
        return res[s.size()];
    }
};