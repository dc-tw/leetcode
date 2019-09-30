class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char c : letters){
            if(target>=c)continue;
            else return c;
        }
        return letters[0];
    }
};