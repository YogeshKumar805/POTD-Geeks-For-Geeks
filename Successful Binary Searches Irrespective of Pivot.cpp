class Solution {
public:
    int countAlwaysFound(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        vector<int> left_max(n), right_min(n);
        
        left_max[0] = arr[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i - 1], arr[i]);
        }
        
        right_min[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_min[i] = min(right_min[i + 1], arr[i]);
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            bool greater_left = (i == 0 || left_max[i - 1] < arr[i]);
            bool smaller_right = (i == n - 1 || right_min[i + 1] > arr[i]);
            if (greater_left && smaller_right) {
                count++;
            }
        }
        
        return count;
    }
};
