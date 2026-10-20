class Solution {
  public:
    vector<int> lexicographicallyLargest(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        
        int left = 0;
        int right = 0;
        
        bool isEven = (arr[left] % 2 == 0);
        
        while(right < n) {
            
            bool currentEven = (arr[right] % 2 == 0);
            
            if(currentEven != isEven) {
                sort(arr.begin() + left, arr.begin() + right, greater<int>());
            }
            
            while(((arr[left] % 2 == 0) != currentEven) && (left <= right)) {
                isEven = currentEven;
                left++;
            }
            
            right++;
        }
        
        sort(arr.begin() + left, arr.end(), greater<int>());
        
        return arr;
    }
};
