class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        int n=arr.size();
        int count=1;
        if(n==1){
            return n;
        }
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]!=1){
                count++;
            }
        }
        return count;
    }
};
