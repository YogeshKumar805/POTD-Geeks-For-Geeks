class Solution {
    public int maxDistance(int[] arr) {
        // Code here
        int max = 0;
        HashMap<Integer, Integer> hm = new HashMap<>();
        for(int i = 0; i< arr.length; i++){
            hm.put(arr[i], i);
        }
        
        for(int i = 0; i < arr.length; i++){
            if(hm.containsKey(arr[i])){
                max = Math.max(max, hm.get(arr[i]) - i);
            }
        }
        return max;
    }
}
