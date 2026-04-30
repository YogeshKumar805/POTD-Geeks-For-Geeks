class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n = arr.size();
        int mid = n / 2;
        
        for (int i=0; i<mid; i++) {
            
            int left = arr[i];
            int right = arr[i];
            if (2*i+1 < n) {
                left= arr[2*i+1];
            }
            if (2*i+2 < n) {
                right = arr[2*i+2];
            }
            
            if (arr[i] < left || arr[i] < right) return false;
        }
        
        return true;
    }
};
