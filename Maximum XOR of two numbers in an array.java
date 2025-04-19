class Solution {
    public int maxXor(int[] arr) {
        // code here
        int mask=0, max=0;
        for(int i=31;i>=0;i--){
            mask=mask | (1<<i);
            Set<Integer> set= new HashSet<>();
            for(int n:arr)
                set.add(mask & n);
               
            int tmp = max | (1<< i);
            for(int prefix : set){
                if(set.contains(tmp ^ prefix)){
                    max = tmp;
                    break ;
                }
            }
        }
        return max;
    }
}
