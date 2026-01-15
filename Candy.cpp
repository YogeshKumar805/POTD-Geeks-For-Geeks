class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
         vector<int>ans(arr.size() , 1);
        for(int i=1;i<arr.size() ; i++){
            if(arr[i]> arr[i-1])ans[i] = ans[i-1]+1;
        }
        for(int i=arr.size() -2 ; i>=0 ;i--){
            if(arr[i]> arr[i+1])ans[i]  = max(ans[i] , ans[i+1]+1);
        }
        int sum = 0;
        for(auto i: ans)sum+=i;
        return sum;
    }
};
