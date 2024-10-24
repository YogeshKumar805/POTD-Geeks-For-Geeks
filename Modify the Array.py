class Solution:
    def modifyAndRearrangeArr(self, arr):
        n = len(arr)
        if n == 0:
            return arr

        # First pass: Merge adjacent duplicates
        i = 0
        for j in range(1, n):
            if arr[i] == arr[j] and arr[i] != 0:
                arr[i] *= 2
                arr[j] = 0  # Mark the merged element as zero
            i += 1

        # Second pass: Move all non-zero elements to the front
        non_zero_index = 0
        for i in range(n):
            if arr[i] != 0:
                arr[non_zero_index] = arr[i]
                non_zero_index += 1

        # Fill the rest of the array with zeros
        for i in range(non_zero_index, n):
            arr[i] = 0

        return arr
