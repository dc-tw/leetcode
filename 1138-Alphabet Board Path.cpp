class Solution {
public:
    string alphabetBoardPath(string target) {
        map<char,pair<int,int>> tmp;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                char c=(i*5+j)+'a';
                tmp[c]=make_pair(i,j);
            }
        }
        tmp['z']=make_pair(5,0);
        pair<int,int> start=make_pair(0,0);
        string res;
        int n=target.length();
        for(int i=0;i<n;i++){
            char c=target[i];
            if(start==tmp[c])res+='!';
            else{
                if('z'==c || tmp['z']==start){
                    if('z'==c){
                        int h=tmp[c].second-start.second;
                        int v=tmp[c].first-start.first;
                        if(h<0)for(int s=0;s<abs(h);s++)res+='L';
                        if(v>0)for(int s=0;s<v;s++)res+='D';
                        res+='!';
                        start=tmp[c];                          
                    }
                    else{
                        int v=tmp[c].first-start.first;
                        int h=tmp[c].second-start.second;
                        if(v<0)for(int s=0;s<abs(v);s++)res+='U';
                        if(h>0)for(int s=0;s<h;s++)res+='R';
                        res+='!';
                        start=tmp[c];                        
                    }
                }
                else{
                    int v=tmp[c].first-start.first;
                    int h=tmp[c].second-start.second;
                    if(v<0)for(int s=0;s<abs(v);s++)res+='U';
                    else for(int s=0;s<v;s++)res+='D';
                    if(h<0)for(int s=0;s<abs(h);s++)res+='L';
                    else for(int s=0;s<h;s++)res+='R';
                    res+='!';
                    start=tmp[c];
                }
            }
        }
        return res;
    }
};