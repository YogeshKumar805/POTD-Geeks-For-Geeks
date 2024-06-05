class Solution {
    long findSwapValues(long a[], int n, long b[], int m) {
        // Your code goes here
    int temp1 = 0, temp2 = 0;
        for (int i = 0; i < n; i++) {
            temp1 += a[i];
        }
        for (int i = 0; i < m; i++) {
            temp2 += b[i];
        }
        if (temp1 == temp2) {
            return 1;
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int i = 0, j = 0;
        while (i < n && j < m) {
            long sumOfA = temp1 - a[i] + b[j];
            long sumOfB = temp2 - b[j] + a[i];
            if (sumOfA == sumOfB) {
                return 1;
            }
            if (sumOfA > sumOfB) {
                i++;
            } else {
                j++;
            }
        }
        return -1;
    }
}
