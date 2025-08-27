class Solution {
    public int countTriangles(int arr[]) {
          int n = arr.length;
        Arrays.sort(arr);
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            int k = i + 1;
            for (int j = i + 2; j < n; j++) {
                while (k < j && arr[i] + arr[k] <= arr[j]) {
                    k++;
                }
                if (k < j) {
                    count += (j - k);
                }
            }
        }
        return count;
    }
}
