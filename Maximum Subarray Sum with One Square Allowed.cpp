class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int prev_sum_without_sq = arr[0];
        int prev_sum_with_sq =   arr[0] * arr[0];
        
        int maxSum = max(prev_sum_without_sq, prev_sum_with_sq);
        
        
        for (int i = 1; i < n; i++) {
            
            int without_sq = arr[i];
            int with_sq =    arr[i] * arr[i];
            
            int curr_sum_without_sq = max(without_sq, prev_sum_without_sq + without_sq);
            
            int curr_sum_with_sq = max({with_sq, prev_sum_without_sq + with_sq, prev_sum_with_sq + without_sq});
            
            prev_sum_without_sq = curr_sum_without_sq;
            prev_sum_with_sq = curr_sum_with_sq;
            
            maxSum = max({maxSum, prev_sum_without_sq, prev_sum_with_sq});
        }
        
        
        return maxSum;
    }
};
