class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        int res = -1;
        for (int i = 1; i < arr.size(); i++) {
            res = max(res, arr[i] + arr[i - 1]);
        }
        return res;
    }
};
 

