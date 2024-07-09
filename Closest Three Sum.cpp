class Solution {
public:
    int threeSumClosest(std::vector<int>& arr, int target) {
        // Sort the array to use the two-pointer technique
        sort(arr.begin(), arr.end());
        
        int prevDiff = INT_MAX; // Variable to track the minimum difference
        int closestSum = INT_MIN; // Initialize closestSum with the minimum integer value

        // Iterate through each element
        for(int i = 0; i < arr.size() - 2; i++){
            int start = i + 1; // Initialize start pointer
            int end = arr.size() - 1; // Initialize end pointer

            while(start < end){
                int sum = arr[i] + arr[start] + arr[end]; // Calculate the sum of three numbers
                
                // If the exact target sum is found
                if(sum == target) return sum;

                int currentDiff = abs(sum - target);
                
                // Update closestSum if a closer sum is found or if the same difference is found but sum is larger
                if(currentDiff < prevDiff || (currentDiff == prevDiff && sum > closestSum)){
                    prevDiff = currentDiff;
                    closestSum = sum;
                }

                // Move pointers based on the sum comparison with the target
                if(sum < target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return closestSum;
    }
};

