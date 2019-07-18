class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        map<char, char> m;
        map<char, char> m2;
        for (size_t i = 0; i < len; i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = t[i];
            }
            else if (m[s[i]] != t[i]) {
                return false;
            }
            if (m2.find(t[i]) == m2.end()) {
                m2[t[i]] = s[i];
            }
            else if (m2[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};