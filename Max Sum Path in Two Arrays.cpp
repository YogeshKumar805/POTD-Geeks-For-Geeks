class Solution {
public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0;
        int total_sum = 0;
        
        int n = a.size();
        int m = b.size();
        
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                sum1 += a[i++];
            } else if (b[j] < a[i]) {
                sum2 += b[j++];
            } else {
                // Common element found
                total_sum += max(sum1, sum2) + a[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        
        // Add remaining elements
        while (i < n) sum1 += a[i++];
        while (j < m) sum2 += b[j++];
        
        total_sum += max(sum1, sum2);
        
        return total_sum;
    }
};
