class Solution {
    public void sort012(int[] nums) {
    int left = 0, current = 0, right = nums.length - 1;

    while (current <= right) {
        if (nums[current] == 0) {
            // Swap current element with left pointer
            int temp = nums[current];
            nums[current] = nums[left];
            nums[left] = temp;

            left++;
            current++;
        } else if (nums[current] == 1) {
            current++;
        } else {
            // Swap current element with right pointer
                int temp = nums[current];
                nums[current] = nums[right];
                nums[right] = temp;
    
                right--;
            }
        }
    }
}
