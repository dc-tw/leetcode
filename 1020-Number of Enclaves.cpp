class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count=0;
                bool flag=false;
                dfs(A,i,j,count,flag);
                if(!flag)
                {
                    res+=count;                
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& A, int i, int j, int& count, bool& flag)
    {
        if(A[i][j] == 1)
        {
            count++;
            A[i][j]=-1;
            if(false==flag)
            {
                if(i==0 || i==(A.size()-1) || j==0 || j==(A[0].size()-1))
                {
                    flag=true;
                }            
            }
            if(i-1>=0)
            {
                dfs(A,i-1,j,count,flag);
            }
            if(i+1<=A.size()-1)
            {
                dfs(A,i+1,j,count,flag);
            }
            if(j-1>=0)
            {
                dfs(A,i,j-1,count,flag);
            }
            if(j+1<=A[0].size()-1)
            {
                dfs(A,i,j+1,count,flag);
            }
        }
    }
};