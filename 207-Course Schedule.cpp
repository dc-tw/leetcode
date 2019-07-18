class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph_.clear();
        
        for(const auto& p : prerequisites)
            graph_[p[0]].insert(p[1]);
        
        for (int i = 0; i < numCourses; ++i) {
            vector<int> visited(numCourses, 0);
            if (cycle(i, i, visited)) return false;
        }
        
        return true;
    }
    
private:
    unordered_map<int, unordered_set<int>> graph_;
    
    bool cycle(int start, int curr, vector<int>& visited) {        
        if (curr == start && visited[start]) return true;
        if (!graph_.count(curr)) return false;
        
        for (const int next : graph_.at(curr)) {
            if (visited[next]) continue;
            visited[next] = true;
            if (cycle(start, next, visited)) return true;
        }
        return false;
    }
};