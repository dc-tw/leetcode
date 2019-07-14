class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()||board.size() == 0 || board[0].size() == 0)
            return;
        int row=board.size(),column=board[0].size();
         for (int i = 0; i < row; ++i) {
            check(board, i, 0);//first column
            check(board, i, column - 1);//last column
        }
        for (int j = 1; j < column - 1; ++j) {
            check(board, 0, j);// first row
            check(board, row - 1, j);// last row
        }
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < column; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';      
    }
    void check(vector<vector<char>>& board,int x,int y)
    {
        if(board[x][y]=='O'){
            board[x][y]='1';
            if(x>1) check(board,x-1,y);
            if(y>1) check(board,x,y-1);
            if(x<board.size()-1) check(board,x+1,y);
            if(y<board[0].size()-1) check(board,x,y+1);
        }
    }
};