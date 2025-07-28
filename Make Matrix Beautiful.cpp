class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<int> r(n, 0);
        vector<int> c(n, 0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                r[i] += mat[i][j];
                c[j] += mat[i][j];
            }
        }
        
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max({maxi, r[i], c[i]});
        }
        
        int rOp=0, cOp=0;
        for(int i=0;i<n;i++){
            rOp += (maxi - r[i]);
            cOp += (maxi - c[i]);
        }
        
        return max(rOp, cOp);
        
    }
};
