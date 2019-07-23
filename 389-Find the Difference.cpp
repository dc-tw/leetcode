class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map;
        for (char c : s) ++map[c];
        for (char c : t) {
            if (--map[c] < 0) return c;
        }
        return 0;
    }
};