class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        int nlvl = (min(m,n)+1)/2;
        for(int i=0; i<nlvl; i++) {
            int lastRow = m-1-i;
            int lastCol = n-1-i;
            if(lastRow==i) {    // one row remain
                for(int j=i; j<=lastCol; j++)
                    res.push_back(matrix[i][j]);
            }
            else if(lastCol==i) {   // one col remain
                for(int j=i; j<=lastRow; j++)
                    res.push_back(matrix[j][i]);
            }   
            else {
                for(int j=i; j<lastCol; j++) 
                    res.push_back(matrix[i][j]);
                for(int j=i; j<lastRow; j++)
                    res.push_back(matrix[j][lastCol]);
                for(int j=lastCol; j>i; j--)
                    res.push_back(matrix[lastRow][j]);
                for(int j=lastRow; j>i; j--)
                    res.push_back(matrix[j][i]);
            }
        }
        return res;
    }
};