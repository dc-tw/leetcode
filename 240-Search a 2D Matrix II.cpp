class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;

        int i,j,mid,rows = matrix.size(),cols = matrix[0].size();
        int limd = rows-1,limu = 0;

        for(i = 0; i <= limd; i++)
        {
            int l = 0, r = cols-1;
            while(l <= r)
            {
                mid = (l + r)/2;    
                if(matrix[i][mid] < target) l = mid+1;
                else if(matrix[i][mid] > target) r = mid - 1;
                else return true;
            }
        }
        return false;
    }
};