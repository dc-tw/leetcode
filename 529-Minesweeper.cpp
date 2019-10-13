class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        const int M = board.size(), N = board[0].size();
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        } 
        else if (board[x][y] == 'E') {
            int mcount = 0;
            for (auto p : dirs) {
                int nx = x + p.first, ny = y + p.second;
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && board[nx][ny] == 'M') {
                    mcount ++;
                }
            }
            if (mcount > 0) {
                board[x][y] = '0' + mcount;
            } 
            else {
                board[x][y] = 'B';
                for (auto p : dirs) {
                    int nx = x + p.first, ny = y + p.second;
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N && board[nx][ny] == 'E') {
                        vector<int> pos = {nx, ny};
                        updateBoard(board, pos);
                    }
                }
            }
        }
        return board;
    }
private:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 1}, {1, 0}, {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
};