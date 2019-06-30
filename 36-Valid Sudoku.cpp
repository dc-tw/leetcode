class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int board1[9][9] = {0};
        int board2[9][9] = {0};
        int board3[9][9] = {0};
        
        for(int i = 0;i<9;i++)
            for(int j = 0;j<9;j++){
                if(board[i][j]!='.'){
                    int num = board[i][j] - '0' - 1;
                    int k = i/3*3+j/3;
                    if(board1[i][num]||board2[j][num]||board3[k][num])
                        return false;
                    board1[i][num]=board2[j][num]=board3[k][num]=1;
                }
            }
            return true;
    }
};//check every column & row if identical or not