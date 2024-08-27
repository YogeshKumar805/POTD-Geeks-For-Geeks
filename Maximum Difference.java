class Solution {
    public int findMaxDiff(int[] arr) {
        // code here
         int n = arr.length;
        int[] leftSmaller = new int[n];
        int[] rightSmaller = new int[n];

        Stack<Integer> stack = new Stack<>();

        // Find the nearest left smaller element for each element
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                leftSmaller[i] = 0;
            } else {
                leftSmaller[i] = arr[stack.peek()];
            }
            stack.push(i);
        }

        stack.clear();

        // Find the nearest right smaller element for each element
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                rightSmaller[i] = 0;
            } else {
                rightSmaller[i] = arr[stack.peek()];
            }
            stack.push(i);
        }

        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            maxDiff = Math.max(maxDiff, Math.abs(leftSmaller[i] - rightSmaller[i]));
        }

        return maxDiff;
        
    }
}

                  
