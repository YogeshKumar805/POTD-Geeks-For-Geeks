class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int i=arr.size()-1;
        int ans = 0;
        while(i>0){
            if(arr[i]-arr[i-1]<k){
                ans+=arr[i]+arr[i-1];
                i-=2;
            }else{
                i--;
            }
        }
        return ans;
    }
};
