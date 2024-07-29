class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        
        int n=arr.size();
        int m=arr[0].size();
        int mx=-1 , ans=-1;
        
        for(int i=0; i<n;i++){
            int flag=0;
            for(int j=0; j<m ; j++){
                if(arr[i][j]==1 && mx!=m-j){
                    mx=max(mx,m-j);
                    flag=1;
                }
                if(mx==m-j && flag==1){
                    ans=i;
                    break;
                }
            }
        }
        
        return ans;
    }
};

