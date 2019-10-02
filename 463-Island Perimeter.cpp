class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int num = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j] == 1){
                    num += 4;
                    if(i!=0&&grid[i-1][j] == 1) num -= 2;
                    if(j!=0&&grid[i][j-1] == 1) num -= 2;
                }
            }
        }
        return num;
    }
};