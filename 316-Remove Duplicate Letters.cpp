class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, bool> visited;
        unordered_map<char, int> counter;
        string res = "";
        for (char c : s) ++counter[c];
        for (char c : s) {
            --counter[c];
            if (visited[c]) {
                continue;
            }
            while (!res.empty() && counter[res.back()] && c < res.back()) {
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        return res;
    }
};