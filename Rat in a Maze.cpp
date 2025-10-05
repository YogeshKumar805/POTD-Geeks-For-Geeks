class Solution {
public:
    int n;

    void dfs(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& vis,
             string s, vector<string>& ans)
    {
        if(x<0 || x>=n || y<0 || y>=n) return;   // boundaries checked
        if(maze[x][y]==0 || vis[x][y]!=-1) return; // checking blocked or visited

        if(x==n-1 && y==n-1) {
            ans.push_back(s);
            return;
        }

        vis[x][y] = 1; // mark visited

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        char dir[] = {'U', 'R', 'D', 'L'};

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            dfs(nx, ny, maze, vis, s + dir[i], ans);
        }

        vis[x][y] = -1; // mark unvisted for back traversal
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, -1));
        dfs(0,0,maze,vis,"",ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

