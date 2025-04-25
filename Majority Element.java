class Solution {
    static int majorityElement(int arr[]) {
        // code here
     Map<Integer, Integer> result = new HashMap<>();
        int n = arr.length; 

        for (int i = 0; i < arr.length; i++) {
            result.put(arr[i], result.getOrDefault(arr[i], 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry : result.entrySet()) {
            if (entry.getValue() > n / 2) {  
                return entry.getKey(); 
            }
        }

        return -1;
  
    }
}

