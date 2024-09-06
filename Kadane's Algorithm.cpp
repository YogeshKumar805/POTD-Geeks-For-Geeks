class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int sum = 0, ans = arr[0];
        for(auto it: arr){
            sum += it;
            ans = max(ans, sum);
            if(sum<0){
                sum = 0;
            }
        }
        return ans;
    }
};
