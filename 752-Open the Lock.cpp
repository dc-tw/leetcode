class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const string start = "0000";
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count(start)) return -1;
        if (target == start) return 0;
    
        queue<string> q1;
        queue<string> q2;
        unordered_set<string> v1{start};
        unordered_set<string> v2{target};
    
        int s1 = 0;
        int s2 = 0;
        q1.push(start);
        q2.push(target);
        while (!q1.empty() && !q2.empty()) {      
            if (!q1.empty()) ++s1;
            const int size = q1.size();
            for (int i = 0; i < size; ++i) {
                const string curr = q1.front(); 
                q1.pop();
                for (int i = 0; i < 4; ++i)
                    for (int j = -1; j <= 1; j += 2) {
                        string next = curr;
                        next[i] = (next[i] - '0' + j + 10) % 10 + '0';
                        if (v2.count(next)) return s1 + s2;
                        if (dead.count(next) || v1.count(next)) continue; 
                        q1.push(next);
                        v1.insert(next);
                    }
            }
            swap(q1, q2);
            swap(v1, v2);
            swap(s1, s2);
        }
        return -1;
    }
};