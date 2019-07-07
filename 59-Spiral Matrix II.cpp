class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> res(n,vector<int>(n,0));
        int nlvl = n/2;
        int val = 1;
        for(int i=0; i<nlvl; i++) {
            int last = n-1-i;
            for(int j=i; j<last; j++) 
                res[i][j] = val++;
            for(int j=i; j<last; j++)
                res[j][last] = val++;
            for(int j=last; j>i; j--)
                res[last][j] = val++;
            for(int j=last; j>i; j--)
                res[j][i] = val++;
        }
        if(n%2==1) res[n/2][n/2] = val;
        return res; 
    }
};