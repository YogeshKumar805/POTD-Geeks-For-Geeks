class Solution {
    // Function to count the number of subarrays which adds to the given sum.
    static int subArraySum(int arr[], int tar) {
        // add your code here
        HashMap<Integer,ArrayList<Integer>> hm = new HashMap<>();
        int count = 0;
        ArrayList<Integer> list2 = new ArrayList<Integer>();
        list2.add(-1);
        hm.put(0,list2);
        int sum = 0;
        
        for(int i = 0; i < arr.length; i++)
        {
            sum += arr[i];
            if(hm.containsKey(sum-tar))
            {
                count += hm.get(sum-tar).size();
            }
            
            ArrayList<Integer> list = hm.getOrDefault(sum, new ArrayList<>());
            list.add(i);
            hm.put(sum, list);
        }
        
        return count;
    }
}
