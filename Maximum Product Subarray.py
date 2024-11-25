class Solution:

	# Function to find maximum
	# product subarray
	def maxProduct(self,arr):
		# code here
        max_product = arr[0]
        min_product = arr[0]
        result = arr[0]
        
        # Traverse the array starting from the second element
        for i in range(1, len(arr)):
            num = arr[i]
            
            # If the current number is negative, swap max and min
            if num < 0:
                max_product, min_product = min_product, max_product
            
            # Update max_product and min_product
            max_product = max(num, max_product * num)
            min_product = min(num, min_product * num)
            
            # Update the result
            result = max(result, max_product)
        
        return result
