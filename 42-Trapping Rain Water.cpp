class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),idx=0,lefth=0,righth=0,area=0;
        for(int i=0;i<n;i++) idx=height[idx]<=height[i]?i:idx;
        for(int i=0;i<idx;i++){
            if(height[i]<lefth) area+=lefth-height[i];
            else lefth=height[i];
        }
        for(int i=n-1;i>idx;i--){
            if(height[i]<righth) area+=righth-height[i];
            else righth=height[i];
        }
        return area;
    }
};