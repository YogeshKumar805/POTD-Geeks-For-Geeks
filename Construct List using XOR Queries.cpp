class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int> a;
        a.push_back(0);
        int n=queries.size();
        vector<int> last(n+1,0);
        int l=0;
        int cons=0;
        for(auto q : queries){
            if(q[0]==0){
                cons=0;
                a.push_back(q[1]);
                l++;
            }
            else{
                cons=cons^q[1];
                last[l]=cons;
            }
        }
        vector<int> suffix(l+1,0);
        suffix[l]=last[l];
        for(int i=l-1;i>=0;i--){
            suffix[i]=suffix[i+1]^last[i];
        }
        for(int i=0;i<=l;i++){
            a[i]=a[i]^suffix[i];
        }
        sort(a.begin(),a.end());
        return a;
    }
};
