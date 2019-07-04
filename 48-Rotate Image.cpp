class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int i = 0; i < size - 1; i++) {
            for (int j = i; j < size - i - 1; j++) {
                int ii = j;
                int jj = size - i - 1;
                for (int k = 0; k < 3; k ++) {
                    swap(matrix[i][j], matrix[ii][jj]);
                    int ix = ii;
                    ii = jj;
                    jj = size - ix - 1;
                }
            }
        }
    }
};