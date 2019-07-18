class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (n != 1) {
            if (visited.find(n) != visited.end())return false;   
            visited.insert(n);
            int sum = 0;
            while(n){
                sum += ((n % 10)*(n % 10));
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};