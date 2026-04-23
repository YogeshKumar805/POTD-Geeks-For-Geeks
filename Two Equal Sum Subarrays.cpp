class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        long long total = 0;
        
        for(int x : arr) total += x;
        
        if(total % 2 != 0) return false;
        
        long long target = total / 2;
        long long curr = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            curr += arr[i];
            
            if(curr == target) return true;
        }
        
        return false;
    }
};
