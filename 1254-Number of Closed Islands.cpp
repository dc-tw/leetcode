class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    int val=1;
                    dfs(grid,i,j,val);
                    res+=val;
                }
            }
        }
       return res;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int& val)
    {
        if(i<0||i==grid.size()||j<0||j==grid[0].size()){
            val=0;
            return;
        }
        if(grid[i][j]==1)return ;
        grid[i][j]=1;
        dfs(grid,i+1,j,val);
        dfs(grid,i-1,j,val);
        dfs(grid,i,j-1,val);
        dfs(grid,i,j+1,val);
    }
};