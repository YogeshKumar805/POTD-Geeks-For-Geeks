class Solution {
    public int findUnique(int[] arr) {
        // code here
        HashMap<Integer,Integer> mp=new HashMap<>();
        for(int i=0;i<arr.length;i++)
        {
            mp.put(arr[i],mp.getOrDefault(arr[i],0)+1);
        }
        
        for(int key:mp.keySet())
        {
            if(mp.get(key)==1)
            return key;
        }
        
        return -1;
    }
}

