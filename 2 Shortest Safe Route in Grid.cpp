class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
        // code here
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<bool>> safe(n, vector<bool>(m, true));
        
      
        
        auto isSafe = [&](int x, int y) {
            
           if (x < 0 || x >= n || y < 0 || y >= m) {
               return false;
           }
            
            return true;
        };
        
        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < m; j++) {
                
                if (mat[i][j] == 0) {
                    
                    safe[i][j] = false;
                    
                    for (auto & dir : directions) {
                        
                        int x = i + dir[0];
                        int y = j + dir[1];
                        
                        if (isSafe(x, y)) {
                            safe[x][y] = false;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (safe[i][0]) {
                visited[i][0] = true;
                q.push({i, 0, 1});
            }
        }
        
        
        while (!q.empty()) {
            
            auto [i, j, w] = q.front();
            q.pop();
            
            if (j == m-1) {
                return w;
            }
            
            for (auto& dir : directions) {
                
                int x = i + dir[0];
                int y = j + dir[1];
                
                if (isSafe(x, y) && !visited[x][y] && safe[x][y] == 1) {
                    
                    visited[x][y] = true;
                    q.push({x, y, w + 1});
                }
            }
        }
        
        return -1;
    }
};
