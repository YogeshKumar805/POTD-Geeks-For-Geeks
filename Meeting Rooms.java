class Solution {
    static boolean canAttend(int[][] arr) {
        int n = arr.length;

        // Sort the meetings by their start times
        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));

        for (int i = 0; i < n - 1; i++) {

            // Compare the current meeting's end time with the
            // next meeting's start time to check for overlap
            if (arr[i][1] > arr[i + 1][0]) return false;
        }
        return true;
    }
}
