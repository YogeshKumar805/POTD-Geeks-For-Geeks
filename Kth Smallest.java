class Solution {
    public static int kthSmallest(int[] arr, int k) {
        // Your code here
        PriorityQueue<Integer>pq=new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<arr.length;i++)
        {
            pq.add(arr[i]);
            if(pq.size()>k)
            {
                pq.poll();
            }
        }
        return pq.poll();
    }
}

