class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n =(int)arr.size();
        sort(arr.begin(),arr.end());
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if((arr[i]-k)<0)
            continue;
            int maxmH=arr[n-1]-k;
            if(i)
            {
                maxmH=max(maxmH,arr[i-1]+k);
            }
            int minmH=(arr[i]-k);
            
            if(i)
            {
                minmH=min(minmH,arr[0]+k);
            }
            
            ans=min(ans,maxmH-minmH);
        }
        ans=min(ans,arr[n-1]-arr[0]);
        return ans;
    }
};
