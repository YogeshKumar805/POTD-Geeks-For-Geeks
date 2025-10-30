class Solution {
  public:
    
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    
    void bounds(int i, int j, vector<pair<int, int>>& toChange, bool& border, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        if (grid[i][j] == 'X') return;
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = true;
        
        toChange.push_back({i, j});
        if (i==0 || i==n-1 || j==0 || j==m-1) border=true;
        
        
        for (int ix=0; ix<4; ix++) {
            int nr = i+dr[ix];
            int nc = j+dc[ix];
            if (nr>=0 && nr<n && nc>=0 && nc<m && !(vis[nr][nc])) {
                bounds(nr, nc, toChange, border, grid, vis);
            }
        }
    }
    
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 'O' && !(vis[i][j])) {
                    vector<pair<int, int>> toChange;
                    bool border = false;
                    bounds(i, j, toChange, border, grid, vis);
                    
                    if (!border) {
                        for (auto pr:toChange) {
                            grid[pr.first][pr.second] = 'X';
                        }
                    }
                } 
            }
        }
    }
};
