class Solution {
  public:
    int maxProfit(vector<int> &p) {
        int n = p.size(),maxi=0;
        vector<int>v(n,0);
        for(int i=n-1;i>=0;--i){
            if(i==n-1) v[i] = p[i];
            else{
                v[i]=max(p[i],v[i+1]);
            }
            maxi=max(maxi,v[i]-p[i]);
        }
        return maxi;
        
    }
};
