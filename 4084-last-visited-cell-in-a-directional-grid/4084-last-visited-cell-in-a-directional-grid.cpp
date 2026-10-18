
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0, j = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[0][0] = 1;
        while(true) {
            int r = i, c = j;
            if(grid[i][j] == 'L') c--;
            else if(grid[i][j] == 'R') c++;
            else if(grid[i][j] == 'U') r--;
            else if(grid[i][j] == 'D') r++;
            if(r < 0 || r >= m || c < 0 || c >= n) return {i, j};
            if(vis[r][c]) return {i, j};
            i = r;
            j = c;
            vis[i][j] = 1;
        }
    }
};
