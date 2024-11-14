class Solution {
    // Non-static method, so you need to call it on an instance of the class
    public void nearlySorted(int[] arr, int k) {
        // code
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i : arr){
            pq.add(i);
        }
        for(int i = 0; i<arr.length; i++){
            arr[i] = pq.poll();
        }
    }
}
