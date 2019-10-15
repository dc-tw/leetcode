class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int xDir[] = {-1,-1,0,1,1,1,0,-1};
        int yDir[] = {0,-1,-1,-1,0,1,1,1};
        
        long int N = grid.size();
        
        if(N == 1)
            return 1;
        
        if(N == 0 || grid[0][0])
                return -1;
        
        queue<pair<long int,pair<long int,long int>>> q;
        q.push({1,{0,0}});
        
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            long int x = ele.second.first;
            long int y = ele.second.second;
            long int dist = ele.first;
            for(long int i = 0; i < 8; i++){
                long int newX = x + xDir[i];
                long int newY = y + yDir[i];
                
                if(newX < 0 || newX >= N || newY < 0 || newY >= N || grid[newX][newY])
                    continue;
                else{
                    if(newX == N - 1 && newY == N - 1)
                        return dist + 1;
                    else{
                        grid[newX][newY] = 2;
                        q.push({dist+1,{newX,newY}});
                    }
                }
            }
        }
        return -1;
    }
};