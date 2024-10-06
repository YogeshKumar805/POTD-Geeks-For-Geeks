class Solution {
    public int numIslands(char[][] grid) {
        // Code here
        int n=grid.length,m=grid[0].length;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid,n,m);
                    ans++;
                }
            }
        }
        
        return ans;
    }
    private void dfs(int i,int j,char[][] grid,int n,int m){
        if(i>=n || i<0 || j>=m || j<0 || grid[i][j]=='0' || grid[i][j]=='2'){
            return;
        }
        
        grid[i][j]='2';
        
        dfs(i+1,j,grid,n,m); // down
        dfs(i-1,j,grid,n,m); // up
        dfs(i,j+1,grid,n,m); // right
        dfs(i,j-1,grid,n,m); // left
        //diagonals
        dfs(i-1,j-1,grid,n,m); // up->left
        dfs(i-1,j+1,grid,n,m); // up->right
        dfs(i+1,j-1,grid,n,m); // down->left
        dfs(i+1,j+1,grid,n,m); // down->right
    }
}
