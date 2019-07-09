class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry=0;
        int m=a.size()-1, n=b.size()-1;
        while( m>=0 || n>=0 )
        {
            int q = (m>=0)? a[m--]-'0':0;
            int p = (n>=0)? b[n--]-'0':0;
            int k=q+p+carry;
            res= to_string(k%2)+res;
            carry=k/2;
        }
        if(1 == carry) res='1'+res;
        return res;
    }
};