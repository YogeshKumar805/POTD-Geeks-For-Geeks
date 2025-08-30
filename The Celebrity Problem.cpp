class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int celIndex=-1;
        vector<int>temp(n,0);
        //temp store how many ones in each row
        for(int i=0;i<n;i++){
            int cntOne=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) cntOne++;
            }
            temp[i]=cntOne;
        }
        
        for(int j=0;j<n;j++){
            int cntOne=0;
            for(int i=0;i<n;i++){
                if(mat[i][j]==1) cntOne++;
            }
            if(cntOne==n && temp[j]==1) {
                celIndex=j;
                break;
            }
        }
        return celIndex;
    }
};
