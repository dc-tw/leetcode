class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> vis;
        unordered_set<int> dup;

        for (int i = 0; i < n; i++)
            vis[arr[i]]++;

        for (const auto &it : vis) {
            if (dup.find(it.second) != dup.end())
                return false;
            dup.insert(it.second);
        }

        return true;
    }
};