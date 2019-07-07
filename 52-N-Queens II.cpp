class Solution {
public:
    int colision(vector<int> vec,int col)
    {
        if(vec.size() == 0)return 0;
        for(int i = 1;i <= vec.size();i++)
        {
            int now_col = vec[vec.size() - i];
            if(now_col == col)return 1;
            if(now_col == col - i)return 1;
            if(now_col == col + i)return 1;
        }
        return 0;
    }
    void DFS(vector<int> vec, int &count,int N)
    {
        if(vec.size() == N)
        {
            count++;
            return;
        }
        for(int i = 1;i<=N;i++)
        {
            if(!colision(vec,i))
            {
                vec.push_back(i);
                DFS(vec,count,N);
                vec.erase(vec.end()-1);
            }
            
        }
    }
    int totalNQueens(int n) {
        int total  = 0;
        vector<int> vec;
        DFS(vec,total,n);
        return total;
    }
};