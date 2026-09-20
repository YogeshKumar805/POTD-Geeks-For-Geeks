class Solution {
  public:
    
    int find(int i,int j,vector<vector<int>> &sumc,vector<vector<int>> &sumr,vector<vector<char>> &mat){
        
        int n = sumc.size();
        int ans = 0;
        int size = 1;
        
        while(i<n && j<n){
            
            int r1 = i-(size-1);
            int c1 = j;
            int r2 = i;
            int c2 = j-(size-1);
            
            if(mat[r1][c1]!='X')return ans;
            if(mat[r2][c2]!='X')return ans;
            
            if(((sumc[i][j]-sumc[r1][c1]) == size-1) && ((sumr[i][j]-sumr[r2][c2]) == size-1)){
                ans = size;
            }
            
            i++;
            j++;
            size++;
            
        }
        
        return ans;
        
    }
    
    int largestSubsquare(vector<vector<char>> &mat) {
        // code here
        int n = mat.size();
        vector<vector<int>>sumc(n,vector<int>(n,0));
        vector<vector<int>>sumr(n,vector<int>(n,0));
        int ans = 0;
        int pre = 0;
        
        for(int j=0;j<n;j++){
            pre=0;
            for(int i=0;i<n;i++){
                if(mat[i][j] == 'X')sumc[i][j]=1;
                sumc[i][j]+=pre;
                pre = sumc[i][j];
            }
        }
        
        pre = 0;
        for(int i=0;i<n;i++){
            pre=0;
            for(int j=0;j<n;j++){
                if(mat[i][j] == 'X')sumr[i][j]=1;
                sumr[i][j]+=pre;
                pre = sumr[i][j];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                ans = max(ans,find(i,j,sumc,sumr,mat));
                
            }
        }
        
        return ans;
        
    }
};
