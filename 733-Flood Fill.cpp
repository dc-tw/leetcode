class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        int m = image.size();        
        int n = image[0].size();        
        dfs(image, sc, sr, n, m, image[sr][sc], newColor);
        return image;
    }
private:
    void dfs(vector<vector<int>>& image, 
                   int x, int y, int n, int m, int orgColor, int newColor) {
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (image[y][x] != orgColor) return;
        image[y][x] = newColor;
        dfs(image, x + 1, y, n, m, orgColor, newColor);
        dfs(image, x - 1, y, n, m, orgColor, newColor);
        dfs(image, x, y + 1, n, m, orgColor, newColor);
        dfs(image, x, y - 1, n, m, orgColor, newColor);
    }
};