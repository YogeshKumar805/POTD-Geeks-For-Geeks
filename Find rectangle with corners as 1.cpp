class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int m=mat.size(),n=mat[0].size();
        unordered_map<int,vector<int>> ones;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    ones[i].push_back(j);
                    ones[m+j].push_back(i);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && ones[i].size()>1 && ones[m+j].size()>1){
                    for(int v : ones[i]){
                        for(int u : ones[m+j]){
                            if(i!=u && j!=v){
                                if(mat[u][v]==1){
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
