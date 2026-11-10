class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) {
        // code here
        
        unordered_map<int, int> freq;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
            
            if (freq[arr[i]] == k) {
                return arr[i];
            }
        }
        
        
        return -1;
    }
};
