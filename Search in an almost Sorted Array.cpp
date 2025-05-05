// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        
        int n = arr.size();
        
        int l = 0;
        int r = n-1;
        
        while(l <= r ){
            
            int mid = l + (r - l)/2;
            
            if(arr[mid] == target) return mid;
            // check the adjacent elements also as the target may be either on the left or right only
            else if(mid > 0 && arr[mid - 1] == target) return mid-1;
            else if(mid < n - 1 && arr[mid + 1] == target) return mid + 1;
            // normal binary serach logic
            else if(arr[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        
        return -1;
        
    }
};
