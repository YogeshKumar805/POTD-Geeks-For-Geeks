class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n  = arr.size();
        int i = n-1 ;
        int ans = 0;
        for(int j = n-1;  j>0 ; j--){
            while(i>=0 && arr[j] - arr[i] <k)i--;
            ans+= (j - i -1);
        }
        return ans;
    }
};
