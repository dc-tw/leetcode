class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < A.size() && !found; ++i)
            for (int j = 0; j < A[0].size() && !found; ++j)
                if (A[i][j]) {
                    dfs(A, j, i, q);
                    found = true;
                }
    
        int steps = 0;
        int dirs[5] = {0, 1, 0, -1, 0};
        while (!q.empty()) {      
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int tx = x + dirs[i];
                    int ty = y + dirs[i + 1];
                    if (tx < 0 || ty < 0 || tx >= A[0].size() || ty >= A.size() || A[ty][tx] == 2) continue;          
                    if (A[ty][tx] == 1) return steps;
                    A[ty][tx] = 2;
                    q.emplace(tx, ty);
                }
            }
            ++steps;
        }
        return -1;
    }
private:  
    void dfs(vector<vector<int>>& A, int x, int y, queue<pair<int, int>>& q) {
        if (x < 0 || y < 0 || x >= A[0].size() || y >= A.size() || A[y][x] != 1) return;
        A[y][x] = 2;
        q.emplace(x, y);
        dfs(A, x - 1, y, q);
        dfs(A, x, y - 1, q);
        dfs(A, x + 1, y, q);
        dfs(A, x, y + 1, q);
    }
};